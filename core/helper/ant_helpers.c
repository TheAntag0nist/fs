#include "ant_helpers.h"
/////////////////////////////////////////////////////////////////////
//                          DESCRIPTION
/////////////////////////////////////////////////////////////////////
// 1 Kb

// blocks bmp
// inode bmp
// inode table

// N записей в inode create_inodes_table
// 1024 - (N * 88) - (N / 8) - X = 0

// N = 11  (2 bytes for inodes table)
// X = 54 (432 blocks)
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
    else{
        // create bitmaps and table
        create_blocks_bitmap(fl);
        create_inodes_bitmap(fl);
        create_inodes_table(fl);

        unsigned int offset = BYTES_1KB - 
                     (sizeof(ant_blocks_bitmaps) +
                     sizeof(ant_inode_bitmaps) +
                     sizeof(ant_inode) * 11);

        create_empty_offset(fl, offset);
        create_data_section(fl, (help_data.block_sz - 1) * BYTES_1KB);
    }

    return 0;
}

int create_superblock(FILE* fl){
    ant_superblock sb;

    sb.ant_blocks_cnt = help_data.blocks_cnt;
    sb.ant_free_blocks = help_data.blocks_cnt;
    // TODO: think about it
    sb.ant_free_inodes = INODE_ROWS_NUM;
    sb.ant_inodes_cnt = INODE_ROWS_NUM;
    sb.ant_gblock_sz = help_data.block_sz;  
    // TODO: think about it
    sb.last_mount_tm = time(null);
    sb.last_written_tm = time(null);

    fwrite(&sb, sizeof(sb), 1, fl);
    return 0;
}

int create_gdt(FILE* fl){
    int rows = (help_data.block_sz - sizeof(ant_superblock)) / sizeof(ant_gdt_record);
    for(int row_ind = 0; row_ind < rows; ++row_ind){
        ant_gdt_record record;

        record.addr_inodes_bitmap = 0;
        record.addr_inodes_table = 0;
        record.block_status = FREE;

        fwrite(&record, sizeof(record), 1, fl);
    }

    return 0;
}
/////////////////////////////////////////////////////////////////////
//                      BLOCKS BITMAP HELPERS
/////////////////////////////////////////////////////////////////////
int create_blocks_bitmap(FILE* fl){
    ant_blocks_bitmaps blocks_bmp;

    fwrite(&blocks_bmp, sizeof(blocks_bmp), 1, fl);
    return 0;
}
/////////////////////////////////////////////////////////////////////
//                      INODE BITMAP HELPERS
/////////////////////////////////////////////////////////////////////
int create_inodes_bitmap(FILE* fl){
    ant_inode_bitmaps inodes_bmp;

    fwrite(&inodes_bmp, sizeof(inodes_bmp), 1, fl);
    return 0;
}
/////////////////////////////////////////////////////////////////////
//                      INODE TABLE HELPERS
/////////////////////////////////////////////////////////////////////
int create_inodes_table(FILE* fl){
    for(int inode_rows = 0; inode_rows < INODE_ROWS_NUM; ++inode_rows){
        ant_inode inode;

        inode.ant_dt_create = 0;
        inode.ant_name[0] = '\0';
        inode.guid = 0;
        inode.uuid = 0;

        fwrite(&inode, sizeof(inode), 1, fl);     
    }

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
/////////////////////////////////////////////////////////////////////
//                      DATA SECTION HELPERS
/////////////////////////////////////////////////////////////////////
// TODO: check errors
int create_empty_offset(FILE* fl, int bytes){
    char* empty = calloc(null, bytes);
    fwrite(empty, bytes, 1, fl);
    free(empty);
    return 0;
}

int create_data_section(FILE* fl, int section_sz){
    char* data = calloc(null, section_sz);
    fwrite(data, section_sz, 1, fl);
    free(data);
    return 0;
}