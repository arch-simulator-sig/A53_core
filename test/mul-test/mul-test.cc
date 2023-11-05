#include "VMulTest.h"
#include <fmt/core.h>
#include <verilated_vcd_c.h>

static auto *dut = new VMulTest;
VerilatedVcdC *wtrace;
static uint64_t sim_time = 0;

void tick()
{
    dut->clk = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
    wtrace->dump(sim_time);
    sim_time++;
}

int main()
{
    Verilated::traceEverOn(true);
    wtrace = new VerilatedVcdC;
    dut->trace(wtrace, 5);
    wtrace->open("wave.vcd");
    while (1)
    {
        dut->iMulc = 23;
        dut->iMulr = 4;

        tick();

        if (dut->oRsltOK)
        {
            fmt::print("{}\n", dut->oRslt);
            break;
        }
    }
    wtrace->close();
    delete dut;
}