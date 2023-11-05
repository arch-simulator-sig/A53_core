#include "common.h"
#include "device.h"

void Timer::callback(int offset, bool is_write)
{
    Assert(offset == 0 || offset == 4, "rtc address invalid");
    Assert(!is_write, "rtc do not support write");
    if (offset == 4)
    {
        auto us = getTime();
        setValue(0, us, 0xff);
    }
}