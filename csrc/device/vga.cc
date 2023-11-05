#include <common.h>
#include <device.h>

void VGACtl::initScreen()
{
    SDL_Window *window = nullptr;
    char title[] = "npc-video";
    SDL_SetHint(SDL_HINT_NO_SIGNAL_HANDLERS, "1");
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(vmem->width * 2, vmem->height * 2, 0, &window, &renderer);
    SDL_SetWindowTitle(window, title);
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, vmem->width, vmem->height);
}

void VGACtl::updateScreen()
{
    SDL_UpdateTexture(texture, nullptr, vmem->getPtr(), vmem->width * sizeof(uint32_t));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);
    SDL_RenderPresent(renderer);
}

void VGACtl::callback(int offset, bool is_write)
{
    if (is_write && getValue(4))
    {
        updateScreen();
        setValue(4, 0, 0xff);
    }
}