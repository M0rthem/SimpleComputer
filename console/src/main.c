#include "console.h"
#include "mySimpleComputer.h"
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

int main()
{
    if (!isatty(1)) {
        printf("Dont term stdout");
        return 1;
    }
    struct winsize WS;

    if (ioctl(1, TIOCGWINSZ, &WS)) {
        printf("can't get term size");
        return 2;
    }

    if (WS.ws_col < 115 && WS.ws_row < 30) {
        printf("cant open interface on your term");
        return 3;
    }

    mt_clrscr();
    for (int i = 0; i != 128; i++) {
        printCell(i, WHITE, BLACK);
    }
    printCell(0, BLACK, WHITE);
    int value;
    sc_memoryGet(0, &value);
    printDecodedCommand(value);

    printAccumulator();
    printCounters();
    sc_regInit();
    printFlags();
    printTerm(4, 1);
    printTerm(32, 1);
    printTerm(5, 1);
    printTerm(3, 1);
    printTerm(6, 1);
    printTerm(34, 1);
    printTerm(0, 1);
    printCommand();
    mt_gotoXY(1, 30);
    return 0;
}