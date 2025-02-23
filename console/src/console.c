#include "console.h"
#include "myBigChars.h"
#include "mySimpleComputer.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

int main(int argc, char* argv[])
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

    int fd;
    if (WS.ws_col < 115 && WS.ws_row < 30) {
        printf("cant open interface on your term");
        return 3;
    }
    if (argc > 2) {
        printf("too many command argument");
        return -1;
    } else if (argc == 2) {
        fd = open(argv[1], O_RDONLY);
    } else {
        fd = open("font.bin", O_RDONLY);
    }
    if (fd == -1) {
        printf("error open file");
        return -1;
    }
    int count;
    if (bc_bigcahrread(fd, bigchar[0], 18, &count)) {
        printf("error: cant read file");
        return -1;
    }

    mt_clrscr();

    sc_memoryInit();
    sc_accumulatorInit();
    sc_regInit();
    sc_icounterInit();

    sc_memorySet(0, 543);
    sc_memorySet(1, 6577);
    sc_memorySet(2, 7563);
    sc_memorySet(3, 15253);
    sc_memorySet(4, 8398);

    printAccumulator();
    printCounters();
    printCommand();
    sc_regInit();
    printFlags();
    printTerm(4, 1);
    printTerm(32, 1);
    printTerm(5, 1);
    printTerm(3, 1);
    printTerm(6, 1);
    printTerm(34, 1);
    printTerm(0, 1);

    nowRedact = 3;

    for (int i = 0; i != 128; i++) {
        if (i == nowRedact) {
            printCell(i, BLACK, WHITE);
            continue;
        }
        printCell(i, WHITE, BLACK);
    }

    int value;
    sc_memoryGet(nowRedact, &value);
    printDecodedCommand(value);

    bc_box(1, 1, 61, 15, WHITE, BLACK, "Оперативная память", RED, BLACK);
    bc_box(1,
           16,
           61,
           3,
           WHITE,
           BLACK,
           "Редактируемая ячейка (формат)",
           RED,
           WHITE);
    bc_box(62, 1, 23, 3, WHITE, BLACK, "Аккумулятор", RED, BLACK);
    bc_box(85, 1, 23, 3, WHITE, BLACK, "Регист флагов", RED, BLACK);
    bc_box(62, 4, 23, 3, WHITE, BLACK, "Счетчик команд", RED, BLACK);
    bc_box(85, 4, 23, 3, WHITE, BLACK, "Команда", RED, BLACK);
    bc_box(62,
           7,
           46,
           12,
           WHITE,
           BLACK,
           "Редактируемая команда (увеличено)",
           RED,
           WHITE);
    bc_box(67, 19, 11, 7, WHITE, BLACK, "IN-OUT", GREEN, WHITE);
    bc_box(1, 19, 66, 7, WHITE, BLACK, "Кэш процессора", GREEN, WHITE);
    bc_box(78, 19, 31, 7, WHITE, BLACK, "Клавиши", GREEN, WHITE);

    printBigCell();
    mt_gotoXY(1, 30);
    return 0;
}