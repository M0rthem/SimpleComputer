#include "mySimpleComputer.h"
#include <myTerm.h>
#include <stdio.h>

void printCell(int address, enum colors fg, enum colors bg)
{
    mt_setfgcolor(fg);
    mt_setbgcolor(bg);
    int value;
    sc_memoryGet(address, &value);
    int sign = 0;
    int command = 0;
    int opperand = 0;
    if (sign == 0) {
        putchar('+');
    } else {
        putchar('-');
    }
    sc_commandDecode(value, &sign, &command, &opperand);
    printf("%0*X%0*X", 2, command, 2, opperand);
    mt_setdefaultcolor();
}