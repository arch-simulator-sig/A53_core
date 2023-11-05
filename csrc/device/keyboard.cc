#include <common.h>
#include <device.h>

#define KEYDOWN_MASK 0x8000
#define _KEYS(f)                                                                                                              \
    f(ESCAPE) f(F1) f(F2) f(F3) f(F4) f(F5) f(F6) f(F7) f(F8) f(F9) f(F10) f(F11) f(F12) f(GRAVE) f(1) f(2) f(3) f(4) f(5)    \
        f(6) f(7) f(8) f(9) f(0) f(MINUS) f(EQUALS) f(BACKSPACE) f(TAB) f(Q) f(W) f(E) f(R) f(T) f(Y) f(U) f(I) f(O) f(P)     \
            f(LEFTBRACKET) f(RIGHTBRACKET) f(BACKSLASH) f(CAPSLOCK) f(A) f(S) f(D) f(F) f(G) f(H) f(J) f(K) f(L) f(SEMICOLON) \
                f(APOSTROPHE) f(RETURN) f(LSHIFT) f(Z) f(X) f(C) f(V) f(B) f(N) f(M) f(COMMA) f(PERIOD) f(SLASH) f(RSHIFT)    \
                    f(LCTRL) f(APPLICATION) f(LALT) f(SPACE) f(RALT) f(RCTRL) f(UP) f(DOWN) f(LEFT) f(RIGHT) f(INSERT)        \
                        f(DELETE) f(HOME) f(END) f(PAGEUP) f(PAGEDOWN)

#define _KEY_NAME(k) _KEY_##k,
#define SDL_KEYMAP(k) keymap[CONCAT(SDL_SCANCODE_, k)] = CONCAT(_KEY_, k);

enum
{
    _KEY_NONE = 0,
    MAP(_KEYS, _KEY_NAME)
};

void Keyboard::init()
{
    MAP(_KEYS, SDL_KEYMAP)
}

void Keyboard::sendKey(uint8_t scancode, bool is_keydown)
{
    auto am_scancode = keymap[scancode] | (is_keydown ? KEYDOWN_MASK : 0);
    key_queue.push(am_scancode);
}

void Keyboard::callback(int offset, bool is_write)
{
    Assert(!is_write, "serial do not support write");
    assert(offset == 0);
    uint32_t key = _KEY_NONE;
    if (!key_queue.empty())
    {
        key = key_queue.front();
        key_queue.pop();
    }
    setValue(offset, key, 0xf);
}