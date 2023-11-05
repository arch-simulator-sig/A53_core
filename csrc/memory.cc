#include "memory.h"
#include "common.h"
#include "device.h"
#include <cstdint>
#include <iostream>

static uint8_t pmem[CONFIG_MEM_SIZE] = {};

uint8_t *addrGuestToHost(xlen_t gaddr)
{
    return pmem + gaddr - CONFIG_MEM_BASE;
}

xlen_t addrHostToGuest(uint8_t *haddr)
{
    return haddr - pmem + CONFIG_MEM_BASE;
}

// DPI-C
extern "C" void pmem_read(long long raddr, long long *rdata)
{
    // 总是读取地址为`raddr & ~0x7ull`的8字节返回给`rdata`
    if (likely(inPhyMem(raddr)))
    {
        IFDEF(CONFIG_MTRACE_FULL, log("[mtrace-full] address = {:#x} is READ\n", raddr));
        *rdata = readPhyMem<xlen_t>(raddr & ~0x7ull);
    }
    else
    {
        readMmio(raddr, rdata);
    }
}

extern "C" void pmem_write(long long waddr, long long wdata, char wmask)
{
    // 总是往地址为`waddr & ~0x7ull`的8字节按写掩码`wmask`写入`wdata`
    // `wmask`中每比特表示`wdata`中1个字节的掩码,
    // 如`wmask = 0x3`代表只写入最低2个字节, 内存中的其它字节保持不变
    xlen_t data = wdata;
    xlen_t addr = waddr & ~0x7ull;
    if (likely(inPhyMem(waddr)))
    {
        IFDEF(CONFIG_MTRACE_FULL, log("[mtrace-full] address = {:#x} is WRITTEN\n", waddr));
        for (auto i = 0; i < 8; i++)
        {
            if ((wmask >> i) & 1)
            {
                writePhyMem<uint8_t>((addr & ~0x7ull) + i, data >> (8 * i));
            }
        }
    }
    else
    {
        writeMmio(addr, data, wmask);
    }
}

extern "C" xlen_t vaddr_read(xlen_t addr, int len)
{
    switch (len)
    {
    case 1:
        return readPhyMem<uint8_t>(addr);
    case 2:
        return readPhyMem<uint16_t>(addr);
    case 4:
        return readPhyMem<uint32_t>(addr);
    case 8:
        return readPhyMem<uint64_t>(addr);
    default:
        panic("Invalid data len to read!");
        return 0;
    }
}
