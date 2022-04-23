#ifndef ANT_FS_STRUCT_H
#define ANT_FS_STRUCT_H
#include <stdio.h>
#include <stdint.h>

#define FS_NAME 64

typedef struct ant_fs_struct
{
    FILE* fl;
    char name[FS_NAME];
} ant_fs_struct;


#endif