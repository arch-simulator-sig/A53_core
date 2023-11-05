#ifndef __SDB_H__
#define __SDB_H__

#include <stdbool.h>
#ifdef __cplusplus
extern "C"
{
#endif

    extern void init_sdb();

    extern void sdb_mainloop();

    extern void sdb_set_batch_mode();

    extern bool travel_wp();

#ifdef __cplusplus
}
#endif

#endif