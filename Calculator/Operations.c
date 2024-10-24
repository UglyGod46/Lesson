#include "Operations.h"

double Addition(int count_arg, ...) 
{
    va_list args;
    va_start(args, count_arg);
    double result = 0;
    for (int i = 0; i < count_arg; i++) {
        result += va_arg(args, double);
    }
    va_end(args);
    return result;
}

double Subtraction(int count_arg, ...) 
{
    va_list args;
    va_start(args, count_arg);
    double result = va_arg(args, double); 
    for (int i = 1; i < count_arg; i++) {
        result -= va_arg(args, double);
    }
    va_end(args);
    return result;
}

double Multiplication(int count_arg, ...) 
{
    va_list args;
    va_start(args, count_arg);
    double result = 1;
    for (int i = 0; i < count_arg; i++) {
        result *= va_arg(args, double);
    }
    va_end(args);
    return result;
}

double Division(int count_arg, ...) 
{
    va_list args;
    va_start(args, count_arg);
    double result = va_arg(args, double); 
    for (int i = 1; i < count_arg; i++) {
        double divisor = va_arg(args, double);
        if (divisor != 0) {
            result /= divisor;
        } else {
            printf("Ошибка: деление на ноль!\n");
            va_end(args);
            return 0; 
        }
    }
    va_end(args);
    return result;
}
