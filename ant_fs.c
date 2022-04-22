#include "log/logger.h"
#include "commands/commands.h"

int main(void){ 
    char cmd[CMD_STR_SZ];
    int res = 0;

    while(true){
        res = command(cmd);

        if(res == -1)
            warning("Incorrect command");
        else if(res == 0)
            info("Close FileSystem");
    }

    return  0;
}