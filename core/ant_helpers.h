#ifndef ANT_HELPERS_H
#define ANT_HELPERS_H
#include <stdio.h>
#include <malloc.h>

#include "fs_parts/ant_super.h"
#include "fs_parts/ant_inode.h"
#include "fs_parts/ant_gdt.h"
#include "defines.h"

////////////////////////////
//      global helper
////////////////////////////
int file_exist(char* filename);
////////////////////////////
//      fs helper
////////////////////////////
int create_mbr(FILE* fs);

int create_block(FILE* fl,int block_size);
int create_blocks_bitmap(FILE* fl);
int create_inodes_bitmap(FILE* fl);
int create_inodes_table(FILE* fl);
int create_superblock(FILE* fl);
int create_gdt();
////////////////////////////
//      gdt helper
////////////////////////////

////////////////////////////
//      blocks bitmap
////////////////////////////

////////////////////////////
//      inodes bitmap
////////////////////////////

////////////////////////////
//      inode helper
////////////////////////////
mode get_mode(ant_inode inode);
void set_mode(ant_inode* inode, mode md);

void write_inode(FILE* fl, ant_inode inode);
#endif