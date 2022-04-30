#ifndef INODE_H
#define INODE_H

#include <stdint.h>
#include "../defines.h"

#define MAX_LEN 32

typedef struct mode{
    char type : 2;
    char usr_access : 3;
    char grp_access : 3;
} mode;

// based on ext2 fs
typedef struct ant_inode {
    // name and access
    char ant_name[MAX_LEN];
    // type and access
    // 7 6 5 4 3 2 1 0
    //  GRP | USER| TYPE
    mode ant_mode;
    // pointers to data
    void* direct_pointers[12];
    void* single_indirect_pnt;
    // dates
    int32_t ant_dt_create;
    int32_t ant_dt_modif;
    int32_t ant_dt_del;
    // user id and group id
    int16_t uuid;
    int16_t guid;
} ant_inode;

#endif
