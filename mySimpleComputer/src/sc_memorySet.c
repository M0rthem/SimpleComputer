#include "mem.h"

int sc_memorySet(int address, int value)
{
    if (address < 0 || address >= memorySize) {
        return -1;
    }
    if (value > 0 && value < 0x7FF) {
        return -1;
    }
    memory[address].var = value;
    return 0;
}