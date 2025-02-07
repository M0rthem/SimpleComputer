#include "mySimpleComputer.h"
#include <stdio.h>

void printAccumulator(void)
{
    int value = 0;
    sc_accumulatorGet(&value);
    printf("%d", value);
}