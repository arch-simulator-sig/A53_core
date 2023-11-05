
#include <fstream>
#include <sdb.h>

#include "common.h"
#include "debug.h"
#include "device.h"
#include "memory.h"
#include <difftest.h>
#include <disasm.h>
#include <ftrace.h>
#include <getopt.h>
#include <sstream>
#include <vector>

using namespace fmt;

static char *log_file = nullptr;
static char *diff_so_file = nullptr;
static char *img_file = nullptr;
static std::vector<char *> elf_file;
static int difftest_port = 1234;

static const uint32_t builtin_img[] = {0x4d200913, 0x020940b3, 0x0209413b, 0x020951b3, 0x0209523b, 0x020960b3,
                                       0x0209613b, 0x020971b3, 0x0209723b, 0x800009b7, 0xfff00a13, 0x0349c0b3,
                                       0x0349c0bb, 0x0349e0b3, 0x0349e0bb, 0x00100073};

auto parseArgs(int argc, char *argv[])
{
    const struct option table[] = {
        {"batch", no_argument, nullptr, 'b'},
        {"log", required_argument, nullptr, 'l'},
        {"diff", required_argument, nullptr, 'd'},
        {"port", required_argument, nullptr, 'p'},
        {"elf", required_argument, nullptr, 'e'},
        {"help", no_argument, nullptr, 'h'},
        {0, 0, nullptr, 0},
    };
    int o;
    while ((o = getopt_long(argc, argv, "-bhl:e:d:p:", table, nullptr)) != -1)
    {
        switch (o)
        {
        case 'b':
            sdb_set_batch_mode();
            break;
        case 'p':
            std::istringstream(optarg) >> difftest_port;
            break;
        case 'l':
            log_file = optarg;
            break;
        case 'd':
            diff_so_file = optarg;
            break;
        case 'e':
            elf_file.push_back(optarg);
            break;
        case 1:
            img_file = optarg;
            return 0;
        default:
            print("Usage: {} [OPTION...] IMAGE [args]\n\n", argv[0]);
            print("\t-b,--batch              run with batch mode\n");
            print("\t-l,--log=FILE           output log to FILE\n");
            print("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
            print("\t-p,--port=PORT          run DiffTest with port PORT\n");
            print("\t-e,--elf=FILE           load elf FILE to enable function tracer\n");
            print("\n");
            exit(0);
        }
    }
    return 0;
}

std::FILE *log_fp = nullptr;

auto initLog()
{
    if (log_file == nullptr)
    {
        log_fp = stdout;
        return;
    }
    log_fp = std::fopen(log_file, "w");
    assert(log_fp);
    Log("Log is written to {}.", log_file ? log_file : "stdout");
}

auto loadImg()
{
    if (img_file == nullptr)
    {
        Log("No image is given. Use the default build-in image.");
        memcpy(addrGuestToHost(CONFIG_MEM_BASE), builtin_img, sizeof(builtin_img));
        return sizeof(builtin_img); // built-in image size
    }
    std::ifstream file(img_file, std::ios::binary);
    Assert(file.is_open(), "Cannot open {}.", img_file);

    file.seekg(0, std::ios::end);
    unsigned long size = file.tellg();
    Log("The image is {}, size = {}.", img_file, size);

    file.seekg(0, std::ios::beg);
    file.read(reinterpret_cast<char *>(addrGuestToHost(CONFIG_MEM_BASE)), size);

    file.close();
    return size;
}

void init(int argc, char *argv[])
{
    parseArgs(argc, argv);
    initLog();
    auto img_size = loadImg();
    for (auto file : elf_file)
        IFDEF(CONFIG_FTRACE, parse_elf(file));
    init_sdb();
    IFDEF(CONFIG_DIFFTEST, Difftest::get().init(diff_so_file, img_size, difftest_port));
    IFDEF(CONFIG_DEVICE, initDevices());
    init_disasm("riscv64");
}