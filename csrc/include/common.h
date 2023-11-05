#ifndef __COMMON_H__
#define __COMMON_H__

#include <cstdint>
using xlen_t = uint64_t;

#include <fmt/color.h>
#include <fmt/core.h>
#include <fmt/printf.h>

#include <macro.h>

#include <autoconf.h>
#include <debug.h>
#include <log.h>
#include <utils.h>

enum class State
{
    RUNNING,
    STOP,
    END,
    ABORT
};

#endif