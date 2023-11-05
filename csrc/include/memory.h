#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <common.h>

extern uint8_t *addrGuestToHost(xlen_t gaddr);

extern xlen_t addrHostToGuest(uint8_t *haddr);

static inline bool inPhyMem(xlen_t addr)
{
    return addr - CONFIG_MEM_BASE < CONFIG_MEM_SIZE;
}

template <typename LEN> LEN readPhyMem(xlen_t addr)
{
  LEN data = *reinterpret_cast<LEN *>(addrGuestToHost(addr));
  return data;
}

template <typename LEN> void writePhyMem(xlen_t addr, LEN data)
{
  *reinterpret_cast<LEN *>(addrGuestToHost(addr)) = data;
}

#endif