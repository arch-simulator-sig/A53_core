#ifndef __DEBUG_H__
#define __DEBUG_H__

#include <cassert>
#include <common.h>

extern void AssertCleanUp();

#undef Assert
#define Assert(cond, format, ...)       \
    do                                  \
    {                                   \
        if (!(cond))                    \
        {                               \
            Log(format, ##__VA_ARGS__); \
            AssertCleanUp();            \
            assert(cond);               \
        }                               \
    } while (0)

#define panic(format, ...) Assert(0, format, ##__VA_ARGS__)

#endif
