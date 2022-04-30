#ifndef ANT_FS_STRUCT_H
#define ANT_FS_STRUCT_H
#include <stdio.h>
#include <stdint.h>

#include "defines.h"

// rewrite name as pointer + size (dynamic string)
typedef struct ant_fs_struct{
    FILE* fl;
    char name[PATH_SZ];
} ant_fs_struct;


#endif