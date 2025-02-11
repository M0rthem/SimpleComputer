#include <stdio.h>
#include <string.h>
#include <unistd.h>

int mt_gotoXY(int x, int y)
{
    char buffer[50];
    sprintf(buffer, "033[%d;%dH", x, y);
    unsigned int byte_count = strlen(buffer);
    int flag = 0;
    flag = write(1, buffer, byte_count);
    if (flag < byte_count) {
        return -1
    }
    return 0;
}
