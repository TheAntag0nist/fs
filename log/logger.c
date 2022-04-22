#include "logger.h"

void bit_depth(char* res){
    if(sizeof(int*) == 4)
        strcpy(res, "Bit Death: x86");
    else if(sizeof(int*) == 8)
        strcpy(res, "Bit Death: x64");
}

const char* curr_date_time(){
    time_t tm = time(NULL);
    return (const char*) ctime(&tm);
}

const char* replace_char(char srch, char replace, char* str){
    for(int i = 0; i < strlen(str); ++i)
        if(str[i] == srch)
            str[i] = replace;

    return str;
}

void message( const char* msg, msg_types type){
    // recalculate size of arrays
    char msg_type_str[60];
    char temp_str[40];

    msg_type_str[0] = '\0';
    temp_str[0] = '\0';

    switch (type)
    {
        case NONE:
        #ifdef unix
            set_color(GREEN);
        #endif
            strcat(temp_str, "[ ");
            strcat(temp_str, curr_date_time());
            strcat(temp_str, "]");
            strcpy(msg_type_str, temp_str);
            break;
        case INFO:
        #ifdef unix
            set_color(GREEN);
        #endif
            strcat(temp_str, "[ INF ");
            strcat(temp_str, curr_date_time());
            strcat(temp_str, "]");
            strcpy(msg_type_str, temp_str);
            break;
        case WARN:
        #ifdef unix
            set_color(YELLOW);
        #endif
            strcat(temp_str, "[ WRN ");
            strcat(temp_str, curr_date_time());
            strcat(temp_str, "]");
            strcpy(msg_type_str, temp_str);
            break;
        case ERROR:
        #ifdef unix
            set_color(RED);
        #endif
            strcat(temp_str, "[ ERR ");
            strcat(temp_str, curr_date_time());
            strcat(temp_str, "]");
            strcpy(msg_type_str, temp_str);
            break;
    }


    replace_char( '\n', ' ', msg_type_str);
    printf("%s\t", msg_type_str);

    #ifdef unix
        reset_color();
    #endif

    printf("%s\n", msg);
}

void info(const char* msg){
    message(msg, INFO);
}

void warning(const char* msg){
    message(msg, WARN);
}

void error(const char* msg){
    message(msg, ERROR);
}

void delimiter(char ch, int val){
    if(val <= 0 )
        val = 33;

    for(int i = 0; i < val; ++i)
        printf("%c",ch);
    printf("\n");
}