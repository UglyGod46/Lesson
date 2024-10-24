#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef double (*Operation)(int count_arg, ...);

double Addition(int count_arg, ...)
{
    va_list factor;
    va_start(factor, count_arg);
    int result = 0;
    for(int i = 0; i < count_arg; i++)
    {
        result += va_arg(factor, int);
    }
    va_end(factor);
    return result;
}

double Subtraction(int count_args, ...)
{
    va_list factor;
    va_start(factor, count_args);
    int result = va_arg(factor, int);
    for(int i = 0; i < count_args; i++)
    {
        result -= va_arg(factor, int);
    }
    va_end(factor);
    return result;
}

double Multiplication(int count_args, ...)
{
    va_list factor;
    va_start(factor, count_args);
    int result = 1;
    for(int i = 0; i < count_args; i++)
    {
        result *= va_arg(factor, int);
    }
    va_end(factor);
    return result;
}

double Division(int count_args, ...)
{
    va_list factor;
    va_start(factor, count_args);
    int result = va_arg(factor, int);
    for(int i = 0; i < count_args; i++)
    {
        result /= va_arg(factor, int);
    }
    va_end(factor);
    return result;
}

typedef struct{
    char *name;
    Operation func;
} Command;

Command *commands = NULL;
int command_count = 0;

void Add_command(char *name, Operation func)
{
    commands = realloc(commands, sizeof(Command) * (command_count + 1));
    commands[command_count].name = strdup(name);
    commands[command_count].func = strdup(func);
    command_count ++; 
}

Operation Find_command(char *name)
{
    for(int i = 0; i < command_count; i++)
    {
        if (strcmp(commands[i].name, name) == 0)
        {
            return commands[i].func;
        }
    }
    return 0;
}

int main()
{
    printf("");
}