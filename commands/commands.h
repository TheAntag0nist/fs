#ifndef COMMANDS_H
#define COMMANDS_H
#include <stdio.h>
#include <string.h>

#include "../core/ant_core.h"
#include "../core/defines.h"
#include "../log/logger.h"

// TODO: rewrite as multi filesystem 
static ant_fs_struct curr_fs;

int command(char* str);

int help_cmd();
int open_fs_cmd();
int create_fs_cmd();
int delete_fs_cmd();
int close_fs_cmd();

int create_dir_cmd();
int create_file_cmd();
int open_dir_cmd();
int open_file_cmd();
int delete_dir_cmd();
int delete_file_cmd();
#endif