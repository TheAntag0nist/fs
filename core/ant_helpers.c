#include "ant_helpers.h"

// Fill with empty data
int craete_mbr(FILE* fs){
    char* empty = calloc(MBR_SZ);
    fwrite( empty, MBR_SZ, 1, fs);
}