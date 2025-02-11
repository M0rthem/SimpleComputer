#include "myTerm.h"
#include <stdio.h>

int setbgcolor(enum colors color)
{
    printf("\033[4%dm", color);
    return 0;
}
