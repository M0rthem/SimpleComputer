#include <sys/ioctl.h>
#include <unistd.h>W

int mt_getscreensize(int* rows, int* cols)
{
    struct winsize ws;
    if (ioctl(1, TIOCGWINSZ, &ws) == -1) {
        return -1;
    }
    *row = ws.ws_row;
    *cols = ws.ws_col;
    return 0;
}