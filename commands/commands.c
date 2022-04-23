#include "commands.h"

int command(char* str){
    if(!strcmp(str, "--help")){
        printf("\t--help - display that data\n");
        printf("\t--exit - close fs\n");
        return 1;
    }

    if(!strcmp(str, "--open_fs")){

        return 1;
    }

    if(!strcmp(str, "--create_fs")){

        return 1;
    }

    if(!strcmp(str, "--exit") || !strcmp(str, "--close"))
        return 0;

    return -1;
}