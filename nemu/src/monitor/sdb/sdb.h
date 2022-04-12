#ifndef __SDB_H__
#define __SDB_H__

#include <common.h>

word_t expr(char *e, bool *success);
void new_wp(char*args);
typedef struct watchpoint WP;
//bool watch_point_changed();
#endif
