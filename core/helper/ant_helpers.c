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

int is_extra_block(int64_t block_ind){
    if((block_ind % 1024 == 0) || 
        (block_ind % 512 == 0) ||
        (block_ind % 256 == 0) ||
        (block_ind % 32 == 0))
        return 1;

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

int create_block(FILE* fl, int64_t block_ind){
    // if it's block with backup gdt and superblock
    if(is_extra_block(block_ind)){
        create_superblock(fl);
        create_gdt(fl);
    }
    // create bitmaps and table
    create_blocks_bitmap(fl);
    create_inodes_bitmap(fl);
    create_inodes_table(fl);

    return 0;
}

int create_superblock(FILE* fl){
    ant_superblock sb;

    sb.ant_blocks_cnt = help_data.blocks_cnt;
    sb.ant_free_blocks = help_data.blocks_cnt;
    sb.ant_free_inodes = 0;
    sb.ant_gblock_sz = help_data.block_sz;
    sb.ant_inodes_cnt = 0;
    sb.last_mount_tm = ctime(null);
    sb.last_written_tm = ctime(null);

    fwrite(&sb, sizeof(sb), 1, fl);
    return 0;
}

int create_gdt(FILE* fl){

    return 0;
}
/////////////////////////////////////////////////////////////////////
//                      BLOCKS HELPERS
/////////////////////////////////////////////////////////////////////
int create_blocks_bitmap(FILE* fl){

    return 0;
}
/////////////////////////////////////////////////////////////////////
//                      INODE BITMAP HELPERS
/////////////////////////////////////////////////////////////////////
int create_inodes_bitmap(FILE* fl){

    return 0;
}
/////////////////////////////////////////////////////////////////////
//                      INODE TABLE HELPERS
/////////////////////////////////////////////////////////////////////
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