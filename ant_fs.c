#include "log/logger.h"
#include "commands/commands.h"
#include "core/defines.h"
#include <locale.h>

int main(void){ 
    char cmd[CMD_STR_SZ];
    int res = 0;

    setlocale(LC_ALL, "");
    // default info
    info("Start FileSYstem Program");
    help_cmd();

    while(true){
        printf("ant:> ");
        scanf("%s", cmd);

        res = command(cmd);

        if(res == -1)
            warning("Incorrect command");
        else if(res == 0){
            info("Close FileSystem Program");
            break;
        }
    }
    return  0;
}