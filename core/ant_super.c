#include <stdio.h>
#include <stdlib.h>

#include "ant_super.h"
#include "log/logger.h"

int main(){
    FILE* fl;

    fl = fopen("fs.ant", "a+");
    if(fl == NULL)
        error("can't open FileSystem");

    return 0;
}