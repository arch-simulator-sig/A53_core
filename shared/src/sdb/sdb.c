#include "sdb.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdarg.h>

static int is_batch_mode = false;

static char *stmt = NULL;

static jmp_buf sdb_env;

typedef struct Memlog Memlog;

struct Memlog
{
    void *ptr;
    Memlog *next;
};

static Memlog head_log;

static Memlog *cur_ptr = &head_log;

void *sdb_calloc(size_t __nmemb, size_t __size)
{
    cur_ptr->next = calloc(1, sizeof(Memlog));
    Assert(cur_ptr->next != NULL, "Fail to allocate memory for a Memlog structure.");
    cur_ptr = cur_ptr->next;
    cur_ptr->ptr = calloc(__nmemb, __size);
    Assert(cur_ptr->ptr != NULL, "Fail to allocate memory.");
    return cur_ptr->ptr;
}

static void discard_memlog()
{
    if (head_log.next == NULL)
        return;
    Memlog *log = head_log.next;
    while (log->ptr != NULL)
    {
        free(log->ptr);
        if (log->next == NULL)
            return;
        log = log->next;
    }
}

static void clear_memlog(Memlog *log)
{
    if (log == NULL)
        return;
    if (log->next == NULL)
    {
        free(log);
        return;
    }
    clear_memlog(log->next);
    log->next = NULL;
    free(log);
    return;
}

void init_wp_pool();

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char *rl_gets()
{
    static char *line_read = NULL;

    if (line_read)
    {
        free(line_read);
        line_read = NULL;
    }

    line_read = readline("(sdb) ");

    if (line_read && *line_read)
    {
        add_history(line_read);
    }

    return line_read;
}

/* output error info */
void sdb_error(char *loc, char *format, ...)
{
    va_list VA_ARGS;
    va_start(VA_ARGS, format);
    if (loc)
        printf("Error: %*s", (int)(loc - stmt), "^");
    else
        printf("Error: ");
    vprintf(format, VA_ARGS);
    printf("\n");
    va_end(VA_ARGS);
    longjmp(sdb_env, 1);
}

void sdb_set_batch_mode()
{
    is_batch_mode = true;
}

void sdb_mainloop()
{
    if (is_batch_mode)
    {
        ASTValue cmd_c(ASTNode * this);
        cmd_c(({
            static ASTNode __t = {.value = {SDB_QUIT}};
            &__t;
        }));
        return;
    }

    for (; (stmt = rl_gets()) != NULL;)
    {
        if (setjmp(sdb_env))
        {
            discard_memlog();
            continue;
        }
        cur_ptr = &head_log;
        clear_memlog(head_log.next);

        Token *tokens = tokenize(stmt);

        ASTNode *ast = parse(tokens);

        ASTValue ret = (ast->handler(ast));

        if (ret.i == SDB_WP)
        {
            remedy_expr(tokens->next);
            delete_AST_node(ast);
        }
        else
        {
            free_AST(ast);
        }
        free_tokens(tokens);

        if (ret.i == SDB_QUIT)
            return;

#ifdef CONFIG_DEVICE
        extern void sdl_clear_event_queue();
        sdl_clear_event_queue();
#endif
    }
}

void init_sdb()
{
    /* Initialize the watchpoint pool. */
    init_wp_pool();
}
