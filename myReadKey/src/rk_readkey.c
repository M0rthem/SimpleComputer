#include "myReadKey.h"
#include <termios.h>
#include <unistd.h>
int rk_readkey(enum keys* key)
{
    rk_mytermsave();
    rk_mytermregime(0, 0, 1, 0, 0);

    char buffer[8];
    int nbytes;
    nbytes = read(0, buffer, 7);
    *key = KEY_OTHER;

    if (nbytes == 1) {
        switch (buffer[0]) {
        case '\n':
            *key = KEY_ENTER;
            break;
        case '\033':
            *key = KEY_ESCAPE;
            break;
        }
    }
    if (nbytes == 3) {
        if (buffer[0] == '\033' && buffer[1] == '[') {
            switch (buffer[2]) {
            case 'A':
                *key = KEY_UP;
                break;
            case 'B':
                *key = KEY_DOWN;
                break;
            case 'C':
                *key = KEY_RIGHT;
                break;
            case 'D':
                *key = KEY_LEFT;
                break;
            }
        }
    } else if (nbytes == 5) {
        if (buffer[0] = '\033' && buffer[1] == '[' && buffer[2] == '1'
                    && buffer[4] == '~') {
            switch (buffer[3]) {
            case '5':
                *key = KEY_F5;
                break;
            case '7':
                *key = KEY_F6;
                break;
            }
        }
    }

    rk_mytermstore();
}