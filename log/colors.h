#ifndef COLORS_H
#define COLORS_H

#include "stdio.h"

// константы ANSI цветов
#define ESCAPE "\x1B"

#define RESET       ESCAPE"[0m"

#define DIM         ESCAPE"[2m"
#define BOLD        ESCAPE"[1m"
#define ITALIC      ESCAPE"[3m"
#define UNDERLINE   ESCAPE"[4m"
#define BLINK       ESCAPE"[5m"

#define CLS         ESCAPE"[2J"
#define CLSCURS     ESCAPE"[0J"
#define CLSLINECURS ESCAPE"[0K"

#define CURSHOME    ESCAPE"[H"
#define SAVEPOS     ESCAPE"[s"
#define LOADPOS     ESCAPE"[u"

#define F_BLACK     ESCAPE"[30m"
#define F_RED       ESCAPE"[31m"
#define F_GREEN     ESCAPE"[32m"
#define F_YELLOW    ESCAPE"[33m"
#define F_BLUE      ESCAPE"[34m"
#define F_MAGENTA   ESCAPE"[35m"
#define F_CYAN      ESCAPE"[36m"
#define F_WHITE     ESCAPE"[37m"
#define F_DEFAULT   ESCAPE"[39m"

#define B_BLACK     ESCAPE"[40m"
#define B_RED       ESCAPE"[41m"
#define B_GREEN     ESCAPE"[42m"
#define B_YELLOW    ESCAPE"[43m"
#define B_BLUE      ESCAPE"[44m"
#define B_MAGENTA   ESCAPE"[45m"
#define B_CYAN      ESCAPE"[46m"
#define B_WHITE     ESCAPE"[47m"
#define B_DEFAULT   ESCAPE"[49m"

// вункция движения курсора
#define gotoxy(x,y) printf(ESCAPE"[%d;%dH", (y), (x))

void set_color(const char* color);
void reset_color();

#endif
