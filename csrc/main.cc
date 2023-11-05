#include "device.h"
#include "difftest.h"
#include "macro.h"
#include <fmt/color.h>
#include <fmt/core.h>
#include <memory.h>
#include <sdb.h>

#include <VTop.h>
#include <common.h>
#include <reg.h>
#include <verilated_vcd_c.h>
using namespace fmt;

void init(int argc, char *argv[]);

State state;

static auto *dut = new VTop;
VerilatedVcdC *wtrace;
const std::unique_ptr<VerilatedContext> ctxp{new VerilatedContext};
static uint64_t dump_cycle = 0;
static uint64_t sim_time = 0;
uint64_t inst_cnt = 0;

bool print_step = false;
constexpr int MAX_INST_TO_PRINT = 10;

extern "C" void halt()
{
    if (state != State::ABORT)
        state = State::END;
}

extern "C" void quit()
{
    halt();
}

void tick(int clk)
{
    dut->clk = clk;
    dut->eval();
#ifdef CONFIG_WTRACE
    if (dump_cycle <= CONFIG_WTRACE_CYCLE_LIMIT && inst_cnt >= CONFIG_WTRACE_START &&
        inst_cnt <= CONFIG_WTRACE_START + CONFIG_WTRACE_COUNT)
    {
        wtrace->dump(sim_cycle);
        dump_cycle++;
    }
#endif
    ctxp->timeInc(1);
}

static bool step_flag = false;

void step()
{
    step_flag = true;
    while (step_flag)
    {
        tick(0);
        tick(1);
    }
}

extern "C" void call_step(long long pc)
{
    step_flag = false;
    inst_cnt++;
    IFDEF(CONFIG_DIFFTEST, Difftest::get().step(pc, cpu_gpr));
}

void reset()
{
    dut->nRst = 0;
    for (auto i = 0; i < 4; i++)
    {
        tick(0);
        tick(1);
    }
    dut->nRst = 1;
}

extern "C" void cpu_exec(uint64_t n)
{
    print_step = (n <= MAX_INST_TO_PRINT);
    if (state == State::END || state == State::ABORT)
    {
        print("Simulation has ended.\n");
        return;
    }
    auto start_time = getTime();
    for (; n > 0; n--)
    {
        updateSdlEvent();
        if (state == State::RUNNING)
        {
            step();
#ifdef CONFIG_WATCHPOINT
            if (travel_wp())
                state = State::STOP;
#endif
            continue;
        }
        if (state == State::STOP)
        {
            state = State::RUNNING;
            break;
        }
        Log("{} at pc = {:#x}",
            state == State::END ? cpu_gpr[10] == 0 ? styled("HIT GOOD TRAP", emphasis::bold | fg(terminal_color::green))
                                                   : styled("HIT BAD TRAP ", emphasis::bold | fg(terminal_color::red))
                                : styled("    ABORT    ", emphasis::bold | fg(terminal_color::red)),
            *cpu_pc);
        break;
    }
    auto end_time = getTime();
    sim_time += end_time - start_time;
}

int main(int argc, char *argv[])
{
    init(argc, argv);
#ifdef CONFIG_WTRACE
    Verilated::traceEverOn(true);
    wtrace = new VerilatedVcdC;
    dut->trace(wtrace, 5);
    wtrace->open("build/wave.vcd");
#endif

    reset();

    sdb_mainloop();

    Log("excuted {0} instructions. IPC = {1:.3f}", fmt::group_digits(inst_cnt),
        (static_cast<double>(inst_cnt) / ctxp->time()) * 2);
    if (sim_time > 0)
        Log("host time spent {} us. simulation frequency = {} inst/s", fmt::group_digits(sim_time),
            fmt::group_digits(inst_cnt * 1000000 / sim_time));
    else
        Log("Finish running in less than 1 us and can not calculate the simulation frequency");

    IFDEF(CONFIG_WTRACE, wtrace->close());
    delete dut;

    return state == State::ABORT || cpu_gpr[10] != 0;
}