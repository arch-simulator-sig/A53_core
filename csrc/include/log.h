#ifndef __LOG_H__
#define __LOG_H__

#include <common.h>
#include <cstdio>

extern std::FILE *log_fp;

template <typename S, typename... Args> void log(const S &format, const Args &...args)
{
    fmt::print(log_fp, format, args...);
    fflush(log_fp);
}

template <typename S, typename... Args> void consoleLog(const fmt::text_style &ts, const S &format, const Args &...args)
{
    fmt::print(ts, format, args...);
    log(format, args...);
}

template <typename S, typename... Args> void consoleLog(const S &format, const Args &...args)
{
    fmt::print(format, args...);
    log(format, args...);
}

#define Log(format, ...)                                                                               \
    do                                                                                                 \
    {                                                                                                  \
        consoleLog(fg(fmt::terminal_color::bright_blue), "[{}:{} {}] ", __FILE__, __LINE__, __func__); \
        consoleLog(fg(fmt::terminal_color::bright_cyan), format, ##__VA_ARGS__);                       \
        consoleLog("\n");                                                                              \
    } while (0)

#endif