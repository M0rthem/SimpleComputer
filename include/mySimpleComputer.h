#ifndef MYSIMPLECOMPUTER_H
#define MYSIMPLECOMPUTER_H

#include "register.h"

int sc_memoryInit(void);
int sc_memorySet(int address, int value);
int sc_memoryGet(int address, int* value);
int sc_memorySave(char* filename);
int sc_memoryLoad(char* filename);

int sc_regInit(void);
int sc_regSet(int reg, int value);
int sc_regGet(int reg, int* value);

int sc_icounterInit(void);
int sc_icounerSet(int value);
int sc_icounterGet(int* value);

int sc_commandEncode(int sign, int command, int opperand, int* value);
int sc_commandDecode(int value, int* sign, int* command, int* opperand);
int sc_commandValidate(int command);

int sc_accumulatorInit(void);
int sc_accumulatorSet(int value);
int sc_accumulatorGet(int* value);

#endif