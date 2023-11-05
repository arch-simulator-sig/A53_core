#include "sdb.h"

#pragma region operators

#define LHS (this->left_child->handler(this->left_child).i)
#define RHS (this->right_child->handler(this->right_child).i)
#define I (this->value.i)
#define S (this->value.str)

#define HANDLER_PAT(op) ASTValue op##_handler(ASTNode *this)
#define BINARY_PAT(op)          \
    HANDLER_PAT(op)             \
    {                           \
        I = LHS SYMBOL(op) RHS; \
        return this->value;     \
    }
#define UNARY_PAT(op)       \
    HANDLER_PAT(op)         \
    {                       \
        I = SYMBOL(op) LHS; \
        return this->value; \
    }

HANDLER_PAT(subcmd)
{
    return this->value;
}
MAP(BINARY_PAT, LOGI_OR, LOGI_AND, BIT_OR, BIT_XOR, BIT_AND, EQ, NEQ, LE, LT, GE, GT, LS, RS, ADD, SUB, MUL);
HANDLER_PAT(DIV)
{
    word_t rhs = RHS;
    Assert(rhs != 0, "Division by zero is illegal.");
    I = LHS / rhs;
    return this->value;
}
HANDLER_PAT(MOD)
{
    word_t rhs = RHS;
    Assert(rhs != 0, "Remainder by zero is illegal.");
    I = LHS % rhs;
    return this->value;
}
MAP(UNARY_PAT, LOGI_NOT, BIT_NOT, POS, NEG);
HANDLER_PAT(DEREF)
{
    I = vaddr_read(LHS, 1);
    return this->value;
}
HANDLER_PAT(reg)
{
    ASTValue val;
    bool success = false;
    val.i = reg_str2val(this->value.str, &success);
    sdb_assert(success, NULL, "Reg %s does not exist.", this->value.str);
    return val;
}
HANDLER_PAT(number)
{
    return this->value;
}

#define OP(op)                                  \
    {                                           \
        STR(SYMBOL(op)), AST_##op, op##_handler \
    }

// declare operator precedence from high to low
static OperatorPrec unary = {5, NULL, {OP(LOGI_NOT), OP(BIT_NOT), OP(POS), OP(NEG), OP(DEREF)}};
static OperatorPrec mul_div_mod = {3, &unary, {OP(MUL), OP(DIV), OP(MOD)}};
static OperatorPrec add_sub = {2, &mul_div_mod, {OP(ADD), OP(SUB)}};
static OperatorPrec shift = {2, &add_sub, {OP(LS), OP(RS)}};
static OperatorPrec relation = {4, &shift, {OP(LE), OP(LT), OP(GE), OP(GT)}};
static OperatorPrec eq = {2, &relation, {OP(EQ), OP(NEQ)}};
static OperatorPrec bit_and = {1, &eq, {OP(BIT_AND)}};
static OperatorPrec bit_xor = {1, &bit_and, {OP(BIT_XOR)}};
static OperatorPrec bit_or = {1, &bit_xor, {OP(BIT_OR)}};
static OperatorPrec logi_and = {1, &bit_or, {OP(LOGI_AND)}};
static OperatorPrec logi_or = {1, &logi_and, {OP(LOGI_OR)}};

#undef OP
#undef LHS
#undef RHS
#undef I
#undef S
#pragma endregion

#define HEAD_OP logi_or

bool is_double_punct(char *str)
{
    OperatorPrec *prec = &HEAD_OP;
    while (prec != NULL)
    {
        for (int i = 0; i < prec->n; i++)
        {
            const char *op = prec->list[i].str;
            if (op[1] != '\0' && strncmp(str, op, 2) == 0)
                return true;
        }
        prec = prec->next;
    }
    return false;
}

#pragma region AST_node

void delete_AST_node(ASTNode *node)
{
    if (node->type == AST_SUBCMD || node->type == AST_REG)
        free(node->value.str);
    free(node);
}

void free_AST(ASTNode *node)
{
    if (node->left_child)
        free_AST(node->left_child);
    if (node->right_child)
        free_AST(node->right_child);
    delete_AST_node(node);
}

static ASTNode *new_AST_node(ASTNodeType type)
{
    ASTNode *node = sdb_calloc(1, sizeof(ASTNode));
    node->type = type;
    node->left_child = NULL;
    node->right_child = NULL;
    node->handler = NULL;
    return node;
}

static ASTNode *new_AST_binary(ASTNodeType type, ASTNode *left_child, ASTNode *right_child, Handler handler)
{
    ASTNode *node = new_AST_node(type);
    node->left_child = left_child;
    node->right_child = right_child;
    node->handler = handler;
    return node;
}

static ASTNode *new_AST_unary(ASTNodeType type, ASTNode *child, Handler handler)
{
    ASTNode *node = new_AST_node(type);
    node->left_child = child;
    node->handler = handler;
    return node;
}

static ASTNode *new_AST_cmd(Token *cmd)
{
    ASTNode *node = new_AST_node(type_cmd(cmd));
    node->handler = handler_cmd(cmd);
    node->value.i = SDB_RUN;
    return node;
}

static ASTNode *proto_AST_subcmd(int len, char *str)
{
    ASTNode *node = new_AST_node(AST_SUBCMD);
    node->value.str = sdb_calloc(1, (len + 1) * sizeof(char)); // copy str to ensure the accessibility of the AST in the wp_pool
    memcpy(node->value.str, str, len);
    *(node->value.str + len) = '\0';
    node->handler = subcmd_handler;
    return node;
}

static ASTNode *new_AST_subcmd(Token *subcmd)
{
    return proto_AST_subcmd(subcmd->length, subcmd->loc);
}

static ASTNode *new_AST_reg(Token *reg)
{
    ASTNode *node = new_AST_node(AST_REG);
    node->value.str = sdb_calloc(1, (reg->length) * sizeof(char));
    memcpy(node->value.str, reg->loc + 1, reg->length - 1);
    *(node->value.str + reg->length - 1) = '\0';
    // make value.str null-terminated
    // reg->loc : '$' 't' '0' ...
    // node->value.str : 't' '0' '\0'
    node->handler = reg_handler;
    return node;
}

static ASTNode *proto_AST_number(word_t val)
{
    ASTNode *node = new_AST_node(AST_NUMBER);
    node->value.i = val;
    node->handler = number_handler;
    return node;
}

static ASTNode *new_AST_number(Token *number)
{
    return proto_AST_number(number->value);
}

#pragma endregion

#define assert_type(token, tok_type, format, ...) sdb_assert(token->type == tok_type, token->loc + 1, format, ##__VA_ARGS__)

#define assert_str(token, str, format, ...) sdb_assert(token_equal(token, str), token->loc + 1, format, ##__VA_ARGS__)

/* check if currect token is the last one */
#define last_args(token) \
    token = token->next; \
    assert_type(token, TK_EOL, "Unexpected argument.")

/* tokens_ptr returns the position of the pointer in the linked list to the upper level */
static ASTNode *parse_expr(Token *tokens, Token **tokens_ptr);

static ASTNode *parse_number_reg_bracket(Token *tokens, Token **tokens_ptr)
{
    ASTNode *node;
    if (tokens->type == TK_NUM)
    {
        node = new_AST_number(tokens);
    }
    else if (tokens->type == TK_REG)
    {
        node = new_AST_reg(tokens);
    }
    else if (token_equal(tokens, "("))
    {
        node = parse_expr(tokens->next, &tokens);
        assert_str(tokens, ")", "Expected a \")\".");
    }
    else
    {
        node = NULL;
        sdb_error(tokens->loc + 1, "Unexpected token.");
    }
    *tokens_ptr = tokens->next;
    return node;
}

static ASTNode *parse_operator(Token *tokens, Token **tokens_ptr, OperatorPrec *prec)
{
    Assert(prec != NULL, "Invalid Operator.");
    ASTNode *node;
    if (prec == &unary) // unary operators
    {
        for (int i = 0; i < prec->n; i++)
        {
            const Operator *op = &prec->list[i];
            if (token_equal(tokens, op->str))
            {
                // unary must locate behind the expression, so we parse the operator before entering the next level
                node = new_AST_unary(op->type, parse_operator(tokens->next, &tokens, prec), op->handler);
                goto ret;
            }
        }
        node = parse_number_reg_bracket(tokens, &tokens);
    }
    else // binary operators
    {
        node = parse_operator(tokens, &tokens,
                              prec->next); // parse until there is nothing of higher priority in the LHS;
    loop:
        for (int i = 0; i < prec->n; i++)
        {
            const Operator *op = &prec->list[i];
            if (token_equal(tokens, op->str))
            {
                node = new_AST_binary(op->type, node, parse_operator(tokens->next, &tokens, prec->next), op->handler);
                goto loop;
            }
        }
        goto ret;
    }
ret:
    *tokens_ptr = tokens;
    return node;
}

/* In-Order traversal */
static ASTNode *parse_expr(Token *tokens, Token **tokens_ptr)
{
    ASTNode *node = parse_operator(tokens, &tokens, &HEAD_OP);
    *tokens_ptr = tokens;
    return node;
}

static ASTNode *parse_cmd(Token *tokens, Token **tokens_ptr)
{
    assert_type(tokens, TK_CMD, "Expected a command.");
    ASTNode *node;
    ASTNodeType type = type_cmd(tokens);
    sdb_assert(type != NON, tokens->loc, "Command not found.");
    if (type >= AST_CMD_C && type <= AST_CMD_Q) // cmd
    {
        node = new_AST_cmd(tokens);
        last_args(tokens);
    }
    else if (type >= AST_CMD_HELP && type <= AST_CMD_INFO) // cmd subcmd
    {
        node = new_AST_cmd(tokens);
        tokens = tokens->next;
        if (tokens->type == TK_EOL)
        {
            if (type == AST_CMD_HELP)
            {
                node->left_child = proto_AST_subcmd(3, "all");
            }
            else
            {
                sdb_error(tokens->loc + 1, "Expected a subcommand.");
            }
        }
        else
        {
            node->left_child = new_AST_subcmd(tokens);
            last_args(tokens);
        }
    }
    else if (type >= AST_CMD_SI && type <= AST_CMD_D) // cmd expr
    {
        node = new_AST_cmd(tokens);
        tokens = tokens->next;
        if (tokens->type == TK_EOL) // assign default value
        {
            if (type == AST_CMD_SI)
            {
                node->left_child = proto_AST_number(1);
            }
            else
            {
                sdb_error(tokens->loc + 1, "Expected an argument.");
            }
        }
        else
        {
            node->left_child = parse_expr(tokens, &tokens);
        }
    }
    else if (type == AST_CMD_X) // cmd N expr
    {
        node = new_AST_cmd(tokens);
        tokens = tokens->next;
        assert_type(tokens, TK_NUM, "Expected a number.");
        node->left_child = new_AST_number(tokens);
        node->right_child = parse_expr(tokens->next, &tokens);
    }
    else
    {
        panic("Unexpected error: illegal type of the command token \"%s\".", tokens->loc);
    }
    *tokens_ptr = tokens;
    return node;
}

ASTNode *parse(Token *tokens)
{
    ASTNode *node = parse_cmd(tokens, &tokens);
    assert_type(tokens, TK_EOL, "Junk after end of expression.");
    return node;
}