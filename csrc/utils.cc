#include "verilated_vcd_c.h"
#include <common.h>

static uint64_t boot_time = 0;

static uint64_t getCurTime()
{
    struct timespec now;
    clock_gettime(CLOCK_MONOTONIC_COARSE, &now);
    uint64_t us = now.tv_sec * 1000000 + now.tv_nsec / 1000;
    return us;
}

uint64_t getTime()
{
    if (boot_time == 0)
        boot_time = getCurTime();
    uint64_t now = getCurTime();
    return now - boot_time;
}

extern "C" void assert_fail_msg();
extern VerilatedVcdC *wtrace;
void AssertCleanUp()
{
    assert_fail_msg();
    IFDEF(CONFIG_WTRACE, wtrace->close());
}
