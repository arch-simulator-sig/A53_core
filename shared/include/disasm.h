#ifndef __DISASM_H__
#define __DISASM_H__

#ifdef __cplusplus
extern "C"
{
#endif

    extern "C" void init_disasm(const char *triple);
    extern "C" void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);

#ifdef __cplusplus
}
#endif

#endif