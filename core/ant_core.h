#ifndef ANT_CORE_H
#define ANT_CORE_H
#include <stdio.h>
#include <string.h>

#include "fs_parts/ant_fs_struct.h"
#include "helper/ant_helpers.h"
#include "defines.h"

int create_fs(char* name, int blocks_cnt, int block_sz);
int delete_fs(ant_fs_struct* fs);

ant_fs_struct open_fs(char* fs_src);
int close_fs(ant_fs_struct* fs);

int open_fl(ant_fs_struct fs, char* fl_name);
int create_fl(ant_fs_struct fs, char* fl_name);
int read_fl(ant_fs_struct fs, char* fl_name);
int write_fl(ant_fs_struct fs, char* fl_name, char* data, int size);
int delete_fl(ant_fs_struct fs, char* fl_name);
int close_fl(ant_fs_struct fs, char* fl_name);
int move_fl(ant_fs_struct fs, char* src, char* dest);

int create_dir(ant_fs_struct fs);
int close_dir(ant_fs_struct fs);
int open_dir(ant_fs_struct fs);
int delete_dir(ant_fs_struct fs);
int move_dir(ant_fs_struct fs);

#endif