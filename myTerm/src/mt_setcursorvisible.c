#include <stdio.h>

int mt_setcursorvisible(int value)
{
    if (value) {
        printf("\033[?25h\033[?8c");
    } else {
        printf("\033[?25l\033[?1c");
    }
    return 0;
}