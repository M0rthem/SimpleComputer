#include "console.h"
#include "myBigChars.h"
#include "myReadKey.h"
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
    sc_regInit();

    printAccumulator();
    printCounters();
    printCommand();
    printFlags();

    nowRedact = 0;

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
    bc_box(78, 19, 30, 7, WHITE, BLACK, "Клавиши", GREEN, WHITE);

    printBigCell();

    mt_gotoXY(1, 30);

    rk_mytermregime(0, 0, 1, 0, 0);

    enum keys key;
    while (rk_readkey(&key), key != KEY_ESCAPE) {
        rk_mytermregime(0, 0, 1, 0, 0);
        if (key == KEY_OTHER) {
            continue;
        } else if (key == KEY_UP) {
            if (nowRedact < 10) {
                continue;
            }
            printCell(nowRedact, WHITE, BLACK);
            nowRedact -= 10;
        } else if (key == KEY_ENTER) {
            mt_setbgcolor(GREEN);
            mt_setfgcolor(BLACK);
            int y = (nowRedact / 10) + 2;
            int x = (nowRedact % 10) * 6 + 1 + 1;
            mt_gotoXY(x, y);
            write(1, "     ", 5);
            mt_gotoXY(x, y);
            int value;
            if (!rk_readvalue(&value)) {
                while (rk_readkey(&key),
                       key != KEY_ENTER && key != KEY_ESCAPE) {
                }
                if (key == KEY_ENTER) {
                    sc_memorySet(nowRedact, value);

                } else if (key == KEY_ESCAPE) {
                }
            }
            mt_setdefaultcolor();
        } else if (key == KEY_F5) {
            mt_setbgcolor(GREEN);
            mt_setfgcolor(BLACK);
            mt_gotoXY(68, 2);
            write(1, "     ", 5);
            mt_gotoXY(68, 2);
            int value;
            if (!rk_readvalue(&value)) {
                while (rk_readkey(&key),
                       key != KEY_ENTER && key != KEY_ESCAPE) {
                }
                if (key == KEY_ENTER) {
                    sc_accumulatorSet(value);

                } else if (key == KEY_ESCAPE) {
                }
            }
            mt_setdefaultcolor();
            printAccumulator();
        } else if (key == KEY_F6) {
            mt_setbgcolor(GREEN);
            mt_setfgcolor(BLACK);
            mt_gotoXY(67, 5);
            write(1, "  ", 2);
            mt_gotoXY(67, 5);

            int value = 0;

            for (int i = 0; i != 2; i++) {
                while (rk_readkey(&key),
                       !((key >= KEY_ZERO && key <= KEY_NINE)
                         || (key >= KEY_A && key <= KEY_F))) {
                    if (key == KEY_ESCAPE) {
                        break;
                    }
                }
                if (key == KEY_ESCAPE) {
                    break;
                }

                int addCommand = 0;
                if (key >= KEY_ZERO && key <= KEY_NINE) {
                    addCommand = key - 48;
                } else {
                    addCommand = key - 55;
                }
                write(1, &key, 1);
                value <<= 4;
                value |= addCommand;
            }
            mt_setdefaultcolor();
            if (key != KEY_ESCAPE) {
                while (rk_readkey(&key),
                       key != KEY_ENTER && key != KEY_ESCAPE) {
                }
                if (key == KEY_ENTER) {
                    sc_icounerSet(value);

                } else if (key == KEY_ESCAPE) {
                }
            }

            printCounters();
            printCommand();
        } else if (key == KEY_DOWN) {
            if (nowRedact > 117) {
                continue;
            }
            printCell(nowRedact, WHITE, BLACK);
            nowRedact += 10;
        } else if (key == KEY_RIGHT) {
            if (nowRedact == 127) {
                continue;
            }
            printCell(nowRedact, WHITE, BLACK);
            nowRedact++;
        } else if (key == KEY_LEFT) {
            if (nowRedact == 0) {
                continue;
            }
            printCell(nowRedact, WHITE, BLACK);
            nowRedact--;
        }

        printCell(nowRedact, BLACK, WHITE);
        printBigCell();
        int value;
        sc_memoryGet(nowRedact, &value);
        printDecodedCommand(value);
        mt_gotoXY(1, 30);
    }

    rk_mytermregime(1, 0, 0, 0, 0);
    return 0;
}