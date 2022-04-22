#ifndef INODE_H
#define INODE_H

#include <stdint.h>

#define MAX_LEN 32

// based on ext2 fs
struct ant_inode {
    // name and access
    char ant_name[MAX_LEN];
    // type and access
    int8_t ant_mode;
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
};

#endif