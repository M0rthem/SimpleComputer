#include "mySimpleComputer.h"
#include "myTerm.h"
#include <stdio.h>

void printCounters(void)
{
    mt_gotoXY(63, 5);

    int value;
    int sign;
    int command;
    int opperand;
    sc_icounterGet(&value);

    printf(" T: %02X     IC: ", value);

    fflush(stdout);
}