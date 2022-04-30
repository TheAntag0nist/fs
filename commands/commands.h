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

#endif