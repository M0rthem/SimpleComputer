#include "../include/mem.h"

int sc_memoryInit(void)
{
    for (int i = 0; i != memorySize; i++) {
        memory[i] = 0;
    }
    return 0;
}