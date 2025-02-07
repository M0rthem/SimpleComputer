#include "console.h"
#include "mySimpleComputer.h"
#include <stdio.h>

void printOperativ()
{
    int space = 0;
    for (int i = 0; i != 128; i++) {
        if (space == 10) {
            space = 0;
            putchar('\n');
        }
        printCell(i);
        putchar(' ');
        space++;
    }
}

int main()
{
    sc_memoryInit();
    sc_accumulatorInit();
    sc_icounterInit();
    sc_regInit();
    sc_memorySet(0, 3244);
    sc_memorySet(5, 3);
    sc_memorySet(32, 3267);
    sc_memorySet(3, 636);
    sc_memorySet(6, 754);
    sc_memorySet(1, 5256);
    sc_memorySet(76, 6708);
    sc_memorySet(32, 231);
    sc_memorySet(34, 654);
    sc_memorySet(11, 456);
    printOperativ();
    putchar('\n');

    int ind = sc_memorySet(3, 16384);
    printf("its inccorect value: %d\n", ind);

    sc_regSet(REGISTER_DIVIZION_ZERO, 1);
    sc_regSet(REGISTER_OVERFLOW, 1);
    printFlags();
    putchar('\n');

    ind = sc_regSet(15, 1);
    printf("incorrect flag: %d\n", ind);

    sc_accumulatorSet(15);
    printAccumulator();
    putchar('\n');

    ind = sc_accumulatorSet(16384);
    printf("incorrect accumulator: %d\n", ind);

    sc_icounerSet(152);
    printCounters();
    putchar('\n');

    ind = sc_icounerSet(16384);
    printf("incorrect counter: %d\n", ind);

    int cellValue;
    sc_memoryGet(76, &cellValue);
    int sign;
    int command;
    int opperand;
    sc_commandDecode(cellValue, &sign, &command, &opperand);
    printf("for Cell sign - %d command - %d opperand - %d\n",
           sign,
           command,
           opperand);
    putchar('\n');
    sc_accumulatorGet(&cellValue);
    sc_commandDecode(cellValue, &sign, &command, &opperand);
    printf("for accumulator sign - %d command - %X opperand - %X\n",
           sign,
           command,
           opperand);
    int value;
    sc_commandEncode(0, 0x34, 0x34, &value);
    printDecodedCommand(value);
    return 0;
}