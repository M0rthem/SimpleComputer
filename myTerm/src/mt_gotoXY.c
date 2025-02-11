#include <stdio.h>

int mt_gotoXY(int x, int y)
{
    printf("\033[%d;%dH", x, y);
    return 0;
}
