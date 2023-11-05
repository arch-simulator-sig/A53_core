#ifndef __DIFFTEST_H__
#define __DIFFTEST_H__

#include "reg.h"
#include <common.h>

class Difftest
{
  public:
    static Difftest &get()
    {
        static Difftest instance;
        return instance;
    }
    void init(char *ref_so_file, long img_size, int port);

    void step(xlen_t pc, xlen_t *gpr);
    inline void skip()
    {
        skip_ref = true;
    }

  private:
    bool skip_ref = false;
    bool sync_ref = false;

    void (*copyMemory)(xlen_t addr, void *buf, size_t n, bool direction) = nullptr;
    void (*copyRegs)(void *dut, bool direction) = nullptr;
    void (*executeRef)(uint64_t n) = nullptr;
    void (*refRaiseIntr)(uint64_t NO) = nullptr;

    void copyRegsToRef(xlen_t pc, xlen_t *gpr);
    CPUState getRegsFromRef();
    bool checkDiff(const char *name, xlen_t pc, xlen_t ref, xlen_t dut);

  public:
    Difftest(Difftest const &) = delete;
    void operator=(Difftest const &) = delete;

  private:
    enum DiffDirection : bool
    {
        REF_TO_DUT = false,
        DUT_TO_REF = true
    };

    Difftest()
    {
    }
};

#endif