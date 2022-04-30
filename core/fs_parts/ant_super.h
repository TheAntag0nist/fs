#ifndef SUPER_H
#define SUPER_H
#include <stdint.h>

// 48 BYTE
typedef struct ant_superblock {
    int64_t ant_blocks_cnt;
    int64_t ant_inodes_cnt;
    
    int64_t ant_free_inodes;
    int64_t ant_free_blocks;

    int16_t ant_gblock_sz;

    int32_t last_mount_tm;
    int32_t last_written_tm;
} ant_superblock;

#endif
