#include "../include/mem.h"

int sc_memorySet(int address, int value)
{
    if (address < 0 || address >= memorySize) {
        return -1;
    }
    memory[address] = value;
    return 0;
}