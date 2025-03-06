#ifndef MYREADKEY_H
#define MYREADKEY_H

#include <termios.h>

enum keys {
    KEY_UP,
    KEY_DOWN,
    KEY_LEFT,
    KEY_RIGHT,
    KEY_F5,
    KEY_F6,
    KEY_ENTER,
    KEY_ESCAPE,
    KEY_OTHER
};

extern struct termios termOptions;

int rk_mytermsave(void);
int rk_mytermstore(void);
int rk_mytermregime(int regime, int vtime, int vmin, int echo, int sigint);
int rk_readkey(enum keys* key);

#endif