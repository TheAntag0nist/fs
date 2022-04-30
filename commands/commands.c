#include "commands.h"

// write checks
int command(char* str){
    if(!strcmp(str, "--help")){
        help_cmd();
        return 1;
    }

    // filesystem commands
    if(!strcmp(str, "--open_fs")){
        open_fs_cmd();
        return 1;
    }

    if(!strcmp(str, "--create_fs")){
        create_fs_cmd();
        return 1;
    }

    if(!strcmp(str, "--delete_fs")){
        delete_fs_cmd();
        return 1;
    }

    if(!strcmp(str, "--close_fs")){
        close_fs_cmd();
        return 1;
    }

    // commands in filesystem
    // check fs in functions
    if(!strcmp(str, "--create_dir")){

        return 1;
    }

    if(!strcmp(str, "--create_file")){

        return 1;
    }

    if(!strcmp(str, "--open_dir")){

        return 1;
    }

    if(!strcmp(str, "--open_file")){

        return 1;
    }

    if(!strcmp(str, "--delete_dir")){

        return 1;
    }

    if(!strcmp(str, "--delete_file")){

        return 1;
    }

    if(!strcmp(str, "--exit") || !strcmp(str, "--close"))
        return 0;

    // error or unknown command
    return -1;
}

int help_cmd(){
    printf("\t--help - display that data\n");
    printf("\t--open_fs - open fs\n");
    printf("\t--create_fs - create fs\n");
    printf("\t--delete_fs - delete fs\n");
    printf("\t--close_fs - close current fs\n");
    printf("\t--exit - close provider\n");
}

// maybe be rewritten 
int open_fs_cmd(){
    char temp_str[PATH_SZ];
    temp_str[0] = '\0';

    printf("FS file: ");
    scanf("%s", temp_str);

    if(curr_fs.fl != null)
        close_fs(&curr_fs);

    curr_fs = open_fs(temp_str);

    return 0;
}

// maybe be rewritten 
int create_fs_cmd(){
    char temp_str[FS_NAME];
    int block_cnt;
    int block_sz;

    temp_str[0] = '\0';
    printf("\tFileSystem name: ");
    scanf("%s", temp_str); 
    
    printf("\tBlock Number: ");
    scanf("%d", &block_cnt);
    
    printf("\tBlock Size (1, 2, 4, 8): ");
    scanf("%d", &block_sz);
    
    return create_fs(temp_str, block_cnt, block_sz);
}

// maybe be rewritten 
int delete_fs_cmd(){
    return delete_fs(&curr_fs);
}

// maybe be rewritten 
int close_fs_cmd(){
    return close_fs(&curr_fs);
}

int create_dir_cmd(){

    return 0;
}

int create_file_cmd(){

    return 0;
}

int open_dir_cmd(){

    return 0;
}

int open_file_cmd(){

    return 0;
}

int delete_dir_cmd(){

    return 0;
}

int delete_file_cmd(){

    return 0;
}