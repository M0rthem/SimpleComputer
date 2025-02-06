#include "../include/mem.h"
#include <stdio.h>

int sc_memorySave(char* filename);
int sc_memoryLoad(char* filename);
int main()
{
    memory[0].var = 13;
    memory[18].var = 22;
    memory[45].var = 432;
    memory[memorySize - 1].var = 1000;
    sc_memorySave("test");
    memory[0].var = 0;
    memory[18].var = 0;
    memory[45].var = 0;
    memory[memorySize - 1].var = 0;
    sc_memoryLoad("test");
    printf("%d %d %d %d",
           memory[0].var,
           memory[18].var,
           memory[45].var,
           memory[memorySize - 1].var);
}