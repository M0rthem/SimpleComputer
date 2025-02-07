#include "mySimpleComputer.h"

void printCounters(void)
{
    int value;
    sc_icounterGet(&value);
    printf("%d", value);
}