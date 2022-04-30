#ifndef ANT_GDT_H
#define ANT_GDT_H
#include <stdint.h>

// 40 byte's
typedef struct ant_gdt_record {
    int64_t addr_inodes_bitmap;
    int64_t addr_inodes_table;
    int8_t block_status;
} ant_gdt_record;

#endif