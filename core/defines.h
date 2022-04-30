#ifndef DEFINES_H
#define DEFINES_H

typedef unsigned char ubyte;
typedef signed char   byte;

#define false 0
#define true 1
#define False 0
#define True 1
#define FALSE 0
#define TRUE 1

#define null 0

// in Kb
#define BLOCK_1KB 1
#define BLOCK_2KB 2
#define BLOCK_4KB 4
#define BLOCK_8KB 8

// command string max size
#define CMD_STR_SZ 64
// basic fs name size
#define FS_NAME 64
#define FL_NAME 32
// basic path size
#define PATH_SZ 1024
// basic blocks size
#define DEFAULT_BLOCKS_SZ 1024
// basic MBR_SIZE
#define MBR_SZ 1024


enum block_status{
    FREE,
    USED,
    FULL
};

#endif // DEFINES_H
