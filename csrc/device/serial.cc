#include "common.h"
#include "device.h"

void Serial::callback(int offset, bool is_write)
{
    Assert(offset == 0, "serial address invalid");
    Assert(is_write, "serial do not support read");
    putc(getValue(0), stderr);
}