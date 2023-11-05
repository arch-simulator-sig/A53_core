#ifndef __SHARED_H__
#define __SHARED_H__

#include <assert.h>
#include <inttypes.h>
#include <macro.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint64_t word_t;
typedef word_t vaddr_t;

#undef Assert
#define Assert(cond, format, ...) \
    do                            \
    {                             \
        if (!(cond))              \
        {                         \
            assert(cond);         \
        }                         \
    } while (0)

//*compatible with C code

#define log_write(...)                \
    do                                \
    {                                 \
        extern FILE *log_fp;          \
        fprintf(log_fp, __VA_ARGS__); \
    } while (0)

#define _Log(...)               \
    do                          \
    {                           \
        printf(__VA_ARGS__);    \
        log_write(__VA_ARGS__); \
    } while (0)

#define ANSI_FG_BLUE "\33[1;34m"
#define ANSI_NONE "\33[0m"
#define ANSI_FMT(str, fmt) fmt str ANSI_NONE
#define Log(format, ...) _Log(ANSI_FMT("[%s:%d %s] " format, ANSI_FG_BLUE) "\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__)

#define panic(format, ...) Assert(0, format, ##__VA_ARGS__)

#define FMT_WORD_LH "0x%-16" PRIx64
#define FMT_WORD_LD "%-20" PRIu64

void cpu_exec(uint64_t n);
void quit();
void reg_display();
word_t vaddr_read(vaddr_t addr, int len);
word_t reg_str2val(const char *name, bool *success);

#endif