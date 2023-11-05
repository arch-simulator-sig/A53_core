#ifndef __DEVICE_H__
#define __DEVICE_H__

#include <common.h>
#include <queue>
#include <string>

void initDevices();
void updateSdlEvent();

void readMmio(xlen_t addr, long long *rdata);
void writeMmio(xlen_t addr, xlen_t data, char mask);

class Device
{
  public:
    virtual const std::string getName() = 0;

    Device(xlen_t base, xlen_t size) : phy_base(base), size(size)
    {
        host_addr = new uint8_t[size + 8] + 4; // padding to avoid out of bound
    }

    virtual void callback(int, bool) = 0;

    inline bool checkDevice(xlen_t addr)
    {
        return addr >= phy_base && addr < phy_base + size;
    }

    inline int getOffset(xlen_t addr)
    {
        return addr - phy_base;
    }

    xlen_t getValue(int);
    void setValue(int, xlen_t, char);

    uint8_t *getPtr()
    {
        return host_addr;
    }

  private:
    xlen_t phy_base;
    xlen_t size;

    uint8_t *host_addr;
};

class Serial : public Device
{
  public:
    const std::string getName() override
    {
        return "serial";
    };

    Serial(xlen_t base) : Device(base, 8)
    {
    }

    void callback(int, bool) override;
};

class Timer : public Device
{
  public:
    const std::string getName() override
    {
        return "timer";
    };

    Timer(xlen_t base) : Device(base, 8)
    {
    }

    void callback(int, bool) override;
};

#include <SDL2/SDL.h>
class VideoMem : public Device
{
  public:
    const std::string getName() override
    {
        return "vmem";
    };

    static constexpr uint32_t width = 400;
    static constexpr uint32_t height = 300;

    VideoMem(xlen_t base) : Device(base, width * height * sizeof(uint32_t))
    {
    }

    void callback(int, bool) override
    {
    }
};

class VGACtl : public Device
{
  public:
    const std::string getName() override
    {
        return "vgactl";
    };

    VideoMem *vmem;

    VGACtl(xlen_t base, VideoMem *vmem) : Device(base, 8), vmem(vmem)
    {
        setValue(0, vmem->width << 16 | vmem->height, 0xf);
        initScreen();
    }

    void callback(int, bool) override;

  private:
    void initScreen();

    inline void updateScreen();

  private:
    SDL_Renderer *renderer;
    SDL_Texture *texture;
};

class Keyboard : public Device
{
  public:
    const std::string getName() override
    {
        return "keybrd";
    }

    Keyboard(xlen_t base) : Device(base, 8)
    {
        init();
    }
    void sendKey(uint8_t scancode, bool is_keydown);
    void callback(int, bool) override;

  private:
    uint32_t keymap[256];
    std::queue<uint32_t> key_queue;

    void init();
};

#endif