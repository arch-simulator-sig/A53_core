#ifndef __SDB_H__
#define __SDB_H__

#include <setjmp.h>
#include <shared.h>
#include <stdio.h>

// stmt -> cmd args
// args -> subcmd
//       | expr
//       | ε
// expr -> expr bop expr
//       | op expr
//       | (expr)
//       | number
//       | reg
// bop  -> +
//       | -
//       | *
//       | /
//       | ==
//       | !=
//       | >
//       | >=
//       | <
//       | <=
//       | &&
// uop   | +
//       | -
//       | *
// reg  -> $reg_name

/* sdb */

void *sdb_calloc(size_t __nmemb, size_t __size);

void sdb_error(char *loc, char *format, ...);

/* interrupt current statement if assert fails */
#define sdb_assert(cond, loc, format, ...)     \
    if (!(cond))                               \
    {                                          \
        sdb_error(loc, format, ##__VA_ARGS__); \
    }

typedef enum
{
    SDB_RUN,
    SDB_QUIT,
    SDB_WP,
} SdbRet;

/* tokenizer */

typedef enum
{
    TK_CMD,
    TK_NUM, // DEC | HEX
    TK_PUNCT,
    TK_REG, // &reg
    TK_EOL
} TokenType;

typedef struct Token Token;
struct Token
{
    TokenType type;
    Token *next;
    word_t value;
    char *loc;
    int length;
};

void free_tokens(Token *tokens);

bool token_equal(Token *token, const char *str);

Token *tokenize(char *str);

/* parser */

typedef enum
{
    NON = -1,
    // cmd
    AST_CMD_C,
    AST_CMD_Q,
    // cmd subcmd
    AST_CMD_HELP,
    AST_CMD_DIFF,
    AST_CMD_INFO,
    // cmd expr
    AST_CMD_SI,
    AST_CMD_P,
    AST_CMD_W,
    AST_CMD_D,
    // cmd n expr
    AST_CMD_X,
    // subcmd
    AST_SUBCMD,
#define SYM_LOGI_OR ||
    AST_LOGI_OR,
#define SYM_LOGI_AND &&
    AST_LOGI_AND,
#define SYM_BIT_OR |
    AST_BIT_OR,
#define SYM_BIT_XOR ^
    AST_BIT_XOR,
#define SYM_BIT_AND &
    AST_BIT_AND,
#define SYM_EQ ==
    AST_EQ,
#define SYM_NEQ !=
    AST_NEQ,
#define SYM_LE <=
    AST_LE,
#define SYM_LT <
    AST_LT,
#define SYM_GE >=
    AST_GE,
#define SYM_GT >
    AST_GT,
#define SYM_LS <<
    AST_LS,
#define SYM_RS >>
    AST_RS,
#define SYM_ADD +
    AST_ADD,
#define SYM_SUB -
    AST_SUB,
#define SYM_MUL *
    AST_MUL,
#define SYM_DIV /
    AST_DIV,
#define SYM_MOD %
    AST_MOD,
#define SYM_LOGI_NOT !
    AST_LOGI_NOT,
#define SYM_BIT_NOT ~
    AST_BIT_NOT,
#define SYM_POS +
    AST_POS,
#define SYM_NEG -
    AST_NEG,
#define SYM_DEREF *
    AST_DEREF,
    // number reg
    AST_NUMBER,
    AST_REG
} ASTNodeType;

#define SYMBOL(symbol) SYM_##symbol

typedef union ASTValue ASTValue;
union ASTValue {
    word_t i;
    char *str;
};

typedef struct ASTNode ASTNode;

typedef ASTValue (*Handler)(ASTNode *this);

struct ASTNode
{
    ASTNodeType type;
    ASTNode *left_child;
    ASTNode *right_child;
    ASTValue value;
    Handler handler;
};

typedef struct Operator Operator;
struct Operator
{
    const char *str;
    const ASTNodeType type;
    Handler handler;
};

typedef struct OperatorPrec OperatorPrec;
struct OperatorPrec
{
    const int n;
    OperatorPrec *next;
    const Operator list[];
};

bool is_double_punct(char *str);

void delete_AST_node(ASTNode *node);

extern void free_AST(ASTNode *node);

ASTNode *parse(Token *tokens);

/* command */

typedef struct Cmd Cmd;
struct Cmd
{
    const char *name;
    const char *description;
    const ASTNodeType type;
    Handler handler;
};

ASTNodeType type_cmd(Token *token);

Handler handler_cmd(Token *token);

/* watchpoint */

int new_wp(ASTNode *node);
void remedy_expr(Token *expr);

void free_wp(int no);

void print_wp();

#endif
