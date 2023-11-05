#include <common.h>
#include <cstdint>
#include <disasm.h>
#include <fmt/core.h>
#include <ftrace.h>
#include <verilated_dpi.h>

uint32_t inst;

extern xlen_t *cpu_pc;
extern xlen_t *cpu_gpr;

extern uint64_t inst_cnt;
extern bool print_step;

extern "C" void itrace(long long i)
{
    IFDEF(CONFIG_ITRACE, if (inst_cnt < CONFIG_TRACE_START || inst_cnt > CONFIG_TRACE_END) return);
    inst = i;
    char disasm[128];
    disassemble(disasm, sizeof(disasm), *cpu_pc, reinterpret_cast<uint8_t *>(&inst), 4);
    std::string inst_fmt = fmt::format("[itrace] {:#x}: {:02x} {:02x} {:02x} {:02x}  {}\n", *cpu_pc, (inst >> 24) & 0xFF,
                                       (inst >> 16) & 0xFF, (inst >> 8) & 0xFF, inst & 0xFF, disasm);
    log("{}", inst_fmt);
    if (print_step)
        fmt::print("{}", inst_fmt);
        // uniform format with insts in waveforms
#ifdef CONFIG_FTRACE
    if (strncmp(disasm, "j", 1) == 0)
    {
        check_call(*cpu_pc + (SEXT(BITS(inst, 31, 31), 1) << 20 | BITS(inst, 19, 12) << 12 | BITS(inst, 20, 20) << 11 |
                              BITS(inst, 30, 21) << 1));
        check_call((cpu_gpr[BITS(inst, 19, 15)] + SEXT(BITS(inst, 31, 20), 12)) & ~1);
    }
        check_ret(inst);
#endif
}

extern "C" void mtrace(long long addr, int width, bool wr_or_rd, long long data, long long pc)
{
        IFDEF(CONFIG_ITRACE, if (inst_cnt < CONFIG_TRACE_START || inst_cnt > CONFIG_TRACE_END) return);
#ifdef CONFIG_MTRACE
    if (addr >= CONFIG_MTRACE_LEFT && addr <= CONFIG_MTRACE_RIGHT)
        log("[mtrace] address = {:#x} is {} {} bytes at pc = {:#x}. data = {:#x}\n", addr, wr_or_rd ? "WRITTEN" : "READ",
            1 << width, static_cast<uint64_t>(pc), static_cast<uint64_t>(data));
#endif
}