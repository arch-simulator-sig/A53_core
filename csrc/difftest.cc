#include "difftest.h"
#include "reg.h"
#include <common.h>
#include <dlfcn.h>
#include <fmt/color.h>
#include <memory.h>

#ifdef CONFIG_DIFFTEST

void Difftest::copyRegsToRef(xlen_t pc, xlen_t *gpr)
{
    CPUState cpu = {.pc = pc};
    if (gpr != nullptr)
    {
        std::copy(gpr, gpr + 32, cpu.gpr);
    }
    copyRegs(&cpu, DUT_TO_REF);
}

CPUState Difftest::getRegsFromRef()
{
    CPUState ref;
    copyRegs(&ref, REF_TO_DUT);
    return ref;
}

void Difftest::init(char *ref_so_file, long img_size, int port)
{
    Assert(ref_so_file != nullptr, "Difftest .so file does not exist!");

    auto handle = dlopen(ref_so_file, RTLD_LAZY);
    assert(handle);

    copyMemory = reinterpret_cast<void (*)(xlen_t, void *, size_t, bool)>(dlsym(handle, "difftest_memcpy"));
    assert(copyMemory);

    copyRegs = reinterpret_cast<void (*)(void *, bool)>(dlsym(handle, "difftest_regcpy"));
    assert(copyRegs);

    executeRef = reinterpret_cast<void (*)(uint64_t)>(dlsym(handle, "difftest_exec"));
    assert(executeRef);

    refRaiseIntr = reinterpret_cast<void (*)(uint64_t)>(dlsym(handle, "difftest_raise_intr"));
    assert(refRaiseIntr);

    auto ref_difftest_init = reinterpret_cast<void (*)(int)>(dlsym(handle, "difftest_init"));
    assert(ref_difftest_init);

    ref_difftest_init(port);
    copyMemory(CONFIG_MEM_BASE, addrGuestToHost(CONFIG_MEM_BASE), img_size, DUT_TO_REF);
    copyRegsToRef(CONFIG_MEM_BASE, nullptr);

    Log("Differential testing: {}", fmt::styled("ON", fmt::fg(fmt::terminal_color::green)));
    Log("with {}", ref_so_file);
}

bool Difftest::checkDiff(const char *name, xlen_t pc, xlen_t ref, xlen_t dut)
{
    extern State state;
    if (ref != dut)
    {
        Log("{} is different before executing instruction at pc = {:#x}, right = {:#x}, wrong = {:#x}, diff = {:#x}", name, pc,
            ref, dut, ref ^ dut);
        reg_display();
        state = State::ABORT;
        return false;
    }
    return true;
}

void Difftest::step(xlen_t pc, xlen_t *gpr)
{
    if (skip_ref)
    {
        skip_tick--;
        if (skip_tick == 0)
            return;
        if (skip_tick == -1)
        {
            Log("Syncing with REF at {:#x}", pc);
            copyRegsToRef(pc, gpr);
            skip_ref = false;
        }
    }

    auto ref = getRegsFromRef();

    if (!checkDiff("pc", pc, ref.pc, pc))
        return;
    for (auto i = 0; i < 32; i++)
    {
        if (!checkDiff(regs[i], pc, ref.gpr[i], gpr[i]))
            return;
    }

    executeRef(1);
}

#endif
