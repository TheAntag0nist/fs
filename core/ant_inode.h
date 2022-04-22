#ifndef INODE_H
#define INODE_H

#include <stdint.h>
#include "defines.h"

#define MAX_LEN 32
// based on ext2 fs
typedef struct ant_inode {
    // name and access
    char ant_name[MAX_LEN];
    // type and access
    // 7 6 5 4 3 2 1 0
    //  GRP | USER| TYPE
    byte ant_mode;
    // pointers to data
    void* direct_pointers[12];
    void* single_indirect_pnt;
    // dates
    int32_t ant_dt_create;
    int32_t ant_dt_modif;
    int32_t ant_dt_del;
    // user id and group id
    int16_t uuid;
    int16_t guid;
} ant_inode;

static inline void set_ant_mode(ant_inode * node, byte user, byte group, byte type ) {
    // 7 6 5 4 3 2 1 0 -> PC
    // 0 1 2 3 4 5 6 7 -> HUMAN
    node->ant_mode = (type & 0b00000011) |
                     ((user & 0b00000111)<<2) |
                     ((group & 0b00000111)<<5);
}
static inline byte get_ant_group(ant_inode node) {
    return (node.ant_mode & 0b11100000) >> 5;
}
static inline byte get_ant_grp(ant_inode node) {
    return (node.ant_mode & 0b11100000) >> 5;
}
static inline byte get_ant_user(ant_inode node) {
    return (node.ant_mode & 0b00011100) >> 2;
}
static inline byte get_ant_type(ant_inode node) {
    return node.ant_mode & 0b00000011;
}
#endif
