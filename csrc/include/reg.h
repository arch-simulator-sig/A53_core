#ifndef __REG_H__
#define __REG_H__

#include <common.h>

using CPUState = struct
{
    xlen_t gpr[32];
    xlen_t pc;
};

extern xlen_t *cpu_gpr;
extern xlen_t *cpu_pc;
extern const char *regs[];

extern "C" void reg_display();

#endif