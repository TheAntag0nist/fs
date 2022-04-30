#include "ant_core.h"

int create_fs(char* name,int blocks_cnt, int block_sz){
    ant_fs_struct fs;
    fs.name[0] = '\0';
    fs.fl = null;
    
    // save name
    if(!strcmp(name, ""))
        return 1;
    else{
        // rewrite with strncpy
        strcpy(fs.name, name);
        printf("FS_NAME -> %s\n", fs.name);
    }

    // create fs file
    fs.fl = fopen(fs.name, "wb");
    if(fs.fl != null){
        // create mbr
        // now can be just skipped
        create_mbr(fs.fl);

        for(int i = 0; i < blocks_cnt; ++i){
            // create block
        }
    }

    fclose(fs.fl);
}

int delete_fs(ant_fs_struct* fs){ 
    return remove(fs->name);
}

ant_fs_struct open_fs(char* fs_src){
    ant_fs_struct ant_fs = { 0, ""};

    ant_fs.fl = fopen(fs_src, "ab");
    strcpy(ant_fs.name, fs_src);

    return ant_fs;
}

int close_fs(ant_fs_struct* fs){
    return fclose(fs->fl);
}

int write_fl(ant_fs_struct fs, char* data, int size){}
int move_fl(ant_fs_struct fs, char* src, char* dest){}
int delete_fl(ant_fs_struct fs, char* name){}
int read_fl(ant_fs_struct fs, char* name){}

int create_dir(ant_fs_struct fs){}
int close_dir(ant_fs_struct fs){}
int open_dir(ant_fs_struct fs){}
int delete_dir(ant_fs_struct fs){}
int move_dir(ant_fs_struct fs){}
