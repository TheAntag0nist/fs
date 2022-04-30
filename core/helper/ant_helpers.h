#ifndef ANT_HELPERS_H
#define ANT_HELPERS_H
#include <malloc.h>
#include <stdio.h>
#include <time.h>

#include "../fs_parts/ant_bitmaps.h"
#include "../fs_parts/ant_super.h"
#include "../fs_parts/ant_inode.h"
#include "../fs_parts/ant_gdt.h"
#include "../defines.h"
////////////////////////////
//      data helpers
////////////////////////////
typedef struct ant_help_data{
    int blocks_cnt;
    int block_sz;
} ant_help_data;

// global variable
ant_help_data help_data;
////////////////////////////
//      global helper
////////////////////////////
int file_exist(char* filename);
int is_extra_block(int64_t block_ind);
////////////////////////////
//      fs helper
////////////////////////////
int create_mbr(FILE* fs);
int create_superblock(FILE* fl);
int create_block(FILE* fl, int64_t block_ind);
////////////////////////////
//      gdt helper
////////////////////////////
int create_gdt();
////////////////////////////
//      blocks bitmap
////////////////////////////
int create_blocks_bitmap(FILE* fl);
////////////////////////////
//      inodes bitmap
////////////////////////////
int create_inodes_bitmap(FILE* fl);
////////////////////////////
//      inodes table
////////////////////////////
int create_inodes_table(FILE* fl);
////////////////////////////
//      inode helper
////////////////////////////
mode get_mode(ant_inode inode);
void set_mode(ant_inode* inode, mode md);
void write_inode(FILE* fl, ant_inode inode);
////////////////////////////
//      data section helper
////////////////////////////
int create_empty_offset(FILE* fl, int bytes);
int create_data_section(FILE* fl, int section_sz);
#endif