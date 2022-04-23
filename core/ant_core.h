#ifndef ANT_CORE_H
#define ANT_CORE_H
#include <stdio.h>
#include <string.h>

#include "ant_fs_struct.h"
#include "ant_helpers.h"
#include "defines.h"

ant_fs_struct create_fs(char* name, int blocks_cnt, int block_sz);
int delete_fs(ant_fs_struct fs);

int open_fs(ant_fs_struct fs);
int close_fs(ant_fs_struct fs);

int write_fl(ant_fs_struct fs, char* data, int size);
int move_fl(ant_fs_struct fs, char* src, char* dest);
int delete_fl(ant_fs_struct fs, char* name);
int read_fl(ant_fs_struct fs, char* name);

int create_dir(ant_fs_struct fs);
int close_dir(ant_fs_struct fs);
int open_dir(ant_fs_struct fs);
int delete_dir(ant_fs_struct fs);
int move_dir(ant_fs_struct fs);

#endif