#include "sdb.h"

#define NR_WP 32
#define EXPR_LEN 120

typedef struct watchpoint
{
    int NO;
    ASTNode *node;
    ASTValue last_value;
    char expr[EXPR_LEN];
    struct watchpoint *next;
} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool()
{
    int i;
    for (i = 0; i < NR_WP; i++)
    {
        wp_pool[i].NO = i;
        wp_pool[i].node = NULL;
        wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
    }

    head = NULL;
    free_ = wp_pool;
}
int new_wp(ASTNode *node)
{
    if (free_ == NULL)
        sdb_error(NULL, "No idle watchpoint.");
    WP *cur = free_;
    free_ = free_->next;
    cur->node = node;
    cur->last_value = cur->node->handler(cur->node);
    cur->next = head;
    head = cur;
    return cur->NO;
}
void remedy_expr(Token *expr) // a ugly remedy...
{
    int len = 0;
    for (; expr->next != NULL; expr = expr->next)
    {
        len += expr->length;
        if (len >= EXPR_LEN)
        {
            sdb_error(NULL, "Watchpoint expression is too long.");
            free_wp(head->NO);
        }
        strncat(head->expr, expr->loc, expr->length);
        strcat(head->expr, " ");
    }
}
void free_wp(int no)
{
    if (no < 0 || no >= NR_WP)
        sdb_error(NULL, "Illegal watchpoint number.");
    WP *cur = &wp_pool[no];
    if (cur->node == NULL)
        sdb_error(NULL, "The specified watchpoint does not exist.");
    free_AST(cur->node);
    cur->node = NULL;
    memset(cur->expr, 0, EXPR_LEN);

    if (head != cur)
    {
        WP *temp = head;
        while (temp->next != cur)
            temp = temp->next;
        temp->next = cur->next;
    }
    else
    {
        head = cur->next;
    }
    cur->next = free_;
    free_ = cur;
}
bool travel_wp()
{
    WP *cur = head;
    bool ret = false;
    for (; cur != NULL; cur = cur->next)
    {
        ASTValue cur_value = cur->node->handler(cur->node);
        if (memcmp(&cur_value, &cur->last_value, sizeof(ASTValue)))
        {
            ret = true;
            printf("Watchpoint %d hit.\n", cur->NO);
            printf("%s= " FMT_WORD_LH "\n", cur->expr, cur_value.i);
        }
        cur->last_value = cur_value;
    }
    return ret;
}
void print_wp()
{
    WP *cur = head;
    if (!cur)
    {
        printf("No watchpoints currently set.\n");
        return;
    }
    printf("NO  Expr\n");
    for (; cur != NULL; cur = cur->next)
    {
        printf("%2d  %s\n", cur->NO, cur->expr);
    }
}