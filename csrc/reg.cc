
#include <common.h>
#include <reg.h>
#include <verilated_dpi.h>

using namespace fmt;

xlen_t *cpu_gpr = nullptr;
xlen_t *cpu_pc = nullptr;

const char *regs[] = {"zero", "ra", "sp", "gp", "tp", "t0", "t1", "t2", "s0", "s1", "a0",  "a1",  "a2", "a3", "a4", "a5",
                      "a6",   "a7", "s2", "s3", "s4", "s5", "s6", "s7", "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"};

extern "C" void set_gpr_ptr(const svOpenArrayHandle r)
{
    cpu_gpr = reinterpret_cast<xlen_t *>(reinterpret_cast<VerilatedDpiOpenVar *>(r)->datap());
}

extern "C" void set_pc_ptr(const svOpenArrayHandle pc)
{
    cpu_pc = reinterpret_cast<xlen_t *>(reinterpret_cast<VerilatedDpiOpenVar *>(pc)->datap());
}

extern "C" void reg_display()
{
    print("Reg    {:<20}{:<20}\n", "Hex", "Dec");
    print("[pc]   {:#x}\n", *cpu_pc);
    for (auto i = 0; i < 32; i++)
    {
        print("{:<4}   {:<#20x}{:<20}\n", regs[i], cpu_gpr[i], cpu_gpr[i]);
    }
}

extern "C" xlen_t reg_str2val(const char *name, bool *success)
{
    if (strcmp(name, "pc") == 0)
    {
        *success = true;
        return *cpu_pc;
    }
    for (auto i = 0; i < 32; i++)
    {
        if (strcmp(name, regs[i]) == 0)
        {
            *success = true;
            return cpu_gpr[i];
        }
    }
    *success = false;
    return 0;
}

extern uint64_t inst_cnt;
extern "C" void assert_fail_msg()
{
    Log("aborted after {0} instructions.", inst_cnt);
    reg_display();
}