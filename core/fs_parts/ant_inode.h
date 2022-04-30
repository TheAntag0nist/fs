#ifndef INODE_H
#define INODE_H

#include <stdint.h>
#include "../defines.h"

// 1 BYTE
typedef struct mode{
    char type : 2;
    char usr_access : 3;
    char grp_access : 3;
} mode;

// based on ext2 fs
// 88 BYTES
typedef struct ant_inode {
    // name and access
    char ant_name[MAX_LEN];
    // type and access
    // 7 6 5 4 3 2 1 0
    //  GRP | USER| TYPE
    mode ant_mode;
    // pointers to data
    int16_t direct_pointers[14];
    int16_t single_indirect_pnt;
    int64_t indirect_block_ind; 
    // dates
    int32_t ant_dt_create;
    int32_t ant_dt_modif;
    int32_t ant_dt_del;
    // user id and group id
    int16_t uuid;
    int16_t guid;
} ant_inode;

#endif
