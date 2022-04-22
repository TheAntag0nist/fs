#include "colors.h"

void set_color(const char* color){
    printf("%s", color);
}

void reset_color(){
    printf("%s", RESET);
}