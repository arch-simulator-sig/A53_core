#include "sdb.h"
#include <ctype.h>

static Token *new_token(TokenType type, char *begin, char *end)
{
    Token *token = sdb_calloc(1, sizeof(Token));
    token->type = type;
    token->loc = begin;
    token->length = end - begin;
    return token;
}

void free_tokens(Token *tokens)
{
    if (tokens->type == TK_EOL)
    {
        free(tokens);
        return;
    }
    free_tokens(tokens->next);
    free(tokens);
    return;
}

bool token_equal(Token *token, const char *str)
{
    return strncmp(token->loc, str, token->length) == 0 && str[token->length] == '\0';
}

#define next_token(type, begin, end)         \
    cur->next = new_token(type, begin, end); \
    cur = cur->next;

Token *tokenize(char *stmt)
{
    Token head = {};
    Token *cur = &head;
    while (*stmt)
    {
        if (isspace(*stmt))
        {
            stmt++;
            continue;
        }
        char *beg;
        if (isdigit(*stmt))
        {
            next_token(TK_NUM, stmt, stmt);
            beg = stmt;
            word_t val = strtoul(stmt, &stmt, 10); // DEC
            if (val == 0)
            {
                if (*stmt == 'x' || *stmt == 'X') // HEX
                {
                    stmt++;
                    val = strtoul(stmt, &stmt, 16);
                }
            }
            cur->length = stmt - beg; // length of the string but the number
            cur->value = val;
            continue;
        }
        if (*stmt == '$') // reg
        {
            beg = stmt;
            do
            {
                stmt++;
            } while (isalpha(*stmt) || isdigit(*stmt));
            next_token(TK_REG, beg, stmt);
            continue;
        }
        if (ispunct(*stmt))
        {
            beg = stmt;
            stmt++;
            if (is_double_punct(beg))
            {
                stmt++;
            }
            next_token(TK_PUNCT, beg, stmt);
            continue;
        }
        if (isalpha(*stmt)) // cmd
        {
            beg = stmt;
            do
            {
                stmt++;
            } while (isalpha(*stmt) || isdigit(*stmt));
            if (*stmt != '\0' && *stmt != ' ')
            {
                sdb_error(stmt + 1, "Expected an space after commands.");
            }
            next_token(TK_CMD, beg, stmt);
            continue;
        }
        sdb_error(stmt, "Invalid Token.");
    }
    next_token(TK_EOL, stmt, stmt);
    return head.next;
}