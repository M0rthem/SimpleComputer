// #include "term.h"
#include "myTerm.h"
#include <stdio.h>

int setfgcolor(enum colors color)
{
    printf("\033[3%dm", color);
}

int main()
{
    setfgcolor(BLUE);
    printf("FDSFDS");
}