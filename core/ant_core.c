#include "ant_core.h"

ant_fs_struct create_fs(char* name,int blocks_cnt, int block_sz){
    ant_fs_struct fs;
    
    // save name
    if(!strcmp(name, "")){
        strncpy( name, fs.name, FS_NAME - 1);
        fs.name[FS_NAME - 1] = '\0';
    }else{
        // if error
        // return empty fs
        // and not create
        fs.name[0] = '\0';
        fs.fl = null;
        return fs;
    }

    // create fs file
    fs.fl = fopen(fs.name, "w");
    if(fs.fl != null){
        // create mbr
        craete_mbr(fs.fl);
    }
}

int delete_fs(ant_fs_struct fs){
    if(fs.fl != null){
        return remove(fs.name);
    }
    else
        return -1;
}

int open_fs(ant_fs_struct fl);
int close_fs(ant_fs_struct fl);

int write_fl(ant_fs_struct fs, char* data, int size);
int move_fl(ant_fs_struct fs, char* src, char* dest);
int delete_fl(ant_fs_struct fs, char* name);
int read_fl(ant_fs_struct fs, char* name);

int create_dir(ant_fs_struct fs);
int close_dir(ant_fs_struct fs);
int open_dir(ant_fs_struct fs);
int delete_dir(ant_fs_struct fs);
int move_dir(ant_fs_struct fs);
