#include "console.h"
#include "mySimpleComputer.h"
#include <stdio.h>

int main()
{
    mt_clrscr();
    for (int i = 0; i != 128; i++) {
        printCell(i, WHITE, BLACK);
    }
    printAccumulator();
    printCounters();
    printDecodedCommand(12445);
    sc_regInit();
    printFlags();
    printTerm(4, 1);
    printTerm(4, 1);
    printTerm(4, 1);
    printTerm(4, 1);
    printTerm(4, 1);
    printTerm(4, 1);
    mt_gotoXY(1, 30);
    return 0;
}