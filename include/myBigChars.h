#ifndef MYBIGCHARS_H
#define MYBIGCHARS_H

int bc_strlen(char* str);
int bc_printA(char* str);
int bc_setbigcharpos(int* big, int x, int y, int value);
int bc_getbigcharpos(int* big, int x, int y, int* value);
int bc_printbigchar(int big[2], int x, int y, enum colors fg, enum colors bg);

#endif