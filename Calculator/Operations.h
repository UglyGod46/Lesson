#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_MASSIVE 10

typedef double (*Operations)(int, ...);

typedef struct {
    char *name;
    Operations func;
} Command;

extern Command commands[MAX_SIZE_MASSIVE];

void Create_command(char *name, Operations func, Command *command);

int Add_to_massive(Command _comand, Command massive[], int current_size);

double Addition(int count_arg, ...);

double Subtraction(int count_arg, ...);

double Multiplication(int count_arg, ...);

double Division(int count_arg, ...);


