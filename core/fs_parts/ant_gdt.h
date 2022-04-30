#ifndef ANT_GDT_H
#define ANT_GDT_H
#include <stdint.h>

// 33 byte's
struct ant_gdt_record {
    int64_t addr_blocks_bitmap;
    int64_t addr_inodes_bitmap;
    int64_t addr_inodes_table;
    int64_t addr_next_part_gdt;
    int8_t block_status;
};

#endif