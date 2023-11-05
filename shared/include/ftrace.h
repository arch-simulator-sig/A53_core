#ifndef __FTRACE_H__
#define __FTRACE_H__

#include <stdint.h>
#ifdef __cplusplus
extern "C"
{
#endif

    void parse_elf(const char *elf_file);

    void check_call(uint64_t addr);

    void check_ret(uint32_t inst);

#ifdef __cplusplus
}
#endif

#endif