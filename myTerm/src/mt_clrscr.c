#include <stdio.h>

int mt_clrscr(void)
{
    printf("\033[H\033[J");
    return 0;
}