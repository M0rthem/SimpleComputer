#include <mySimpleComputer.h>
#include <myTerm.h>
#include <stdio.h>

char INOUT[5][15] = {"", "", "", "", ""};

void printTerm(int address, int input) // input = 0 вывод иначе ввод
{
    int sign;
    int command;
    int opperand;
    int value;
    sc_memoryGet(address, &value);
    sc_commandDecode(value, &sign, &command, &opperand);

    char buffer[10];
    snprintf(
            buffer,
            sizeof(buffer),
            "%0*X> %c%0*d%0*d",
            2,
            address,
            (sign == 0) ? '+' : '-',
            2,
            command,
            2,
            opperand);

    for (int i = 0; i != 4; i++) {
        snprintf(INOUT[i], sizeof(INOUT[i]), "%s", INOUT[i + 1]);
    }
    snprintf(INOUT[5 - 1], sizeof(INOUT[5 - 1]), "%s", buffer);
    int start_X = 67;
    int start_Y = 19;
    mt_gotoXY(start_X, start_Y);
    for (int i = 0; i != 5; i++) {
        printf("%s", INOUT[i]);
        fflush(stdout);
        start_Y++;
        mt_gotoXY(start_X, start_Y);
    }
    fflush(stdout);
}