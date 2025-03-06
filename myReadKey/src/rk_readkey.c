#include "myReadKey.h"
#include <termios.h>
#include <unistd.h>

int rk_readkey(enum keys* key)
{
    rk_mytermsave();
    rk_mytermregime(0, 0, 0, 0, 0);

    char buffer[8];
    int nbytes;
    nbytes = read(0, buffer, 7);
    key = KEY_OTHER;

    if (nbytes == 3) {
        if (buffer[0] == '\033', buffer[1] == '[') {
            if (buffer[2] == 'A') {
                *key = KEY_UP;
            }
        }
    }

    rk_mytermstore();
}