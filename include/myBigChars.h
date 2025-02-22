#ifndef MYBIGCHARS_H
#define MYBIGCHARS_H

#include "myTerm.h"

int bc_strlen(char* str);
int bc_printA(char* str);
int bc_setbigcharpos(int* big, int x, int y, int value);
int bc_getbigcharpos(int* big, int x, int y, int* value);
int bc_printbigchar(int big[2], int x, int y, enum colors fg, enum colors bg);
int bc_bigcharwrite(int fd, int* big, int count);
int bc_bigcahrread(int fd, int* big, int need_count, int* count);

#endif