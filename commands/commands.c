#include "commands.h"

int command(char* str){
    if(strcmp(str, "--help")){
        printf("");

        return 1;
    }

    return -1;
}