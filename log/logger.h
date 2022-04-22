#ifndef LOGGER_H
#define LOGGER_H

#include <string.h>
#include <stdio.h>
#include <time.h>
#include "colors.h"

enum msg_types{
    NONE,
    INFO,
    WARN,
    ERROR
} typedef msg_types;

void bit_depth(char* res);

const char* curr_date_time();
const char* replace_char(char srch, char replace, char* str);
void message( const char* msg, msg_types type);

void info(const char* msg);
void warning(const char* msg);
void error(const char* msg);

void delimiter(char ch, int val);
#endif