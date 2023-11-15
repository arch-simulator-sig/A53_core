#include "device.h"
#include "common.h"
#include "difftest.h"
#include <vector>

static std::vector<Device *> devices;

Keyboard *kbd;
extern State state;

void updateSdlEvent()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            state = State::END;
            return;
#ifdef CONFIG_KEYBRD
        case SDL_KEYDOWN:
        case SDL_KEYUP: {
            auto k = event.key.keysym.scancode;
            auto is_keydown = event.key.type == SDL_KEYDOWN;
            kbd->sendKey(k, is_keydown);
            break;
        }
#endif
        default:
            break;
        }
    }
}

void initDevices()
{
    IFDEF(CONFIG_SERIAL, devices.push_back(new Serial(CONFIG_SERIAL_MMIO)));
    IFDEF(CONFIG_TIMER, devices.push_back(new Timer(CONFIG_RTC_MMIO)));
#ifdef CONFIG_VGA
    auto vmem = new VideoMem(CONFIG_FB_ADDR);
    devices.push_back(vmem);
    devices.push_back(new VGACtl(CONFIG_VGA_CTL_MMIO, vmem));
#endif
#ifdef CONFIG_KEYBRD
    kbd = new Keyboard(CONFIG_KEYBRD_MMIO);
    devices.push_back(kbd);
#endif
}

xlen_t Device::getValue(int offset)
{
    return *reinterpret_cast<xlen_t *>(host_addr + offset);
}

void Device::setValue(int offset, xlen_t data, char mask)
{
    for (auto i = 0; i < 8; i++)
    {
        if ((mask >> i) & 1)
        {
            host_addr[offset + i] = static_cast<uint8_t>(data >> (8 * i));
        }
    }
}

Device *fetchMmio(xlen_t addr)
{
    for (auto *device : devices)
    {
        if (device->checkDevice(addr))
        {
            Difftest::get().skip(2);
            return device;
        }
    }
    return nullptr;
}

extern uint64_t inst_cnt;

void readMmio(xlen_t addr, long long *rdata)
{
    auto device = fetchMmio(addr);
    Assert(device, "address to READ {:#x} is out of bound", addr);
    IFDEF(CONFIG_DTRACE, if (inst_cnt >= CONFIG_TRACE_START && inst_cnt <= CONFIG_TRACE_END)
                             log("[dtrace] {{{}}} is READ at address {:#x}\n", device->getName(), addr));
    device->callback(device->getOffset(addr), 0);
    *rdata = device->getValue(device->getOffset(addr & ~0x7ull));
}

void writeMmio(xlen_t addr, xlen_t data, char mask)
{
    auto device = fetchMmio(addr);
    Assert(device, "address to WRITE {:#x} is out of bound", addr);
    IFDEF(CONFIG_DTRACE, if (inst_cnt >= CONFIG_TRACE_START && inst_cnt <= CONFIG_TRACE_END) log(
                             "[dtrace] {{{}}} is WRITTEN at address {:#x} with mask {:#x}\n", device->getName(), addr, mask));
    device->setValue(device->getOffset(addr), data, mask);
    device->callback(device->getOffset(addr), 1);
}