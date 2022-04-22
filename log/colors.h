#ifndef COLORS_H
#define COLORS_H

#include "stdio.h"

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define GREEN   "\033[1;32m"
#define WHITE   "\033[1;37m"

void set_color(const char* color);
void reset_color();

#endif