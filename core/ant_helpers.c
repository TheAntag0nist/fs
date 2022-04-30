#include "ant_helpers.h"
/////////////////////////////////////////////////////////////////////
//                      GLOBAL HELPERS
/////////////////////////////////////////////////////////////////////
int file_exist(char* filename){
    FILE* fl = fopen(filename, "r");
    if(fl != null){
        fclose(fl);
        return 1;
    }else
        return 0;
}
/////////////////////////////////////////////////////////////////////
//                          FS HELPERS
/////////////////////////////////////////////////////////////////////
// Fill with empty data
int create_mbr(FILE* fs){
    char* empty = calloc(0, MBR_SZ);
    fwrite( empty, MBR_SZ, 1, fs);
}

int create_block(FILE* fl, int block_size){
    //create_superblock(fl);
    //create_gdt(fl);
    create_blocks_bitmap(fl);
    create_inodes_bitmap(fl);
    create_inodes_table(fl);

    return 0;
}

int create_superblock(FILE* fl){
    ant_superblock sb;

    sb.ant_blocks_cnt = 0;
    sb.ant_free_blocks = 0;
    sb.ant_free_inodes = 0;
    sb.ant_gblock_sz = 0;
    sb.ant_inodes_cnt = 0;
    sb.last_mount_tm = 0;
    sb.last_written_tm = 0;

    fwrite(&sb, sizeof(sb), 1, fl);
    return 0;
}

int create_gdt(FILE* fl){

    return 0;
}

int create_blocks_bitmap(FILE* fl){

    return 0;
}

int create_inodes_bitmap(FILE* fl){

    return 0;
}

int create_inodes_table(FILE* fl){

    return 0;
}
/////////////////////////////////////////////////////////////////////
//                      INODE HELPERS
/////////////////////////////////////////////////////////////////////
inline mode get_mode(ant_inode inode){
    return inode.ant_mode;
}

inline void set_mode(ant_inode* inode, mode md){
    inode->ant_mode = md;
}