#include <stdio.h>
double divide(double a, double b) {
    if (b == 0) {
        fprintf(stderr, "Ошибка: Деление на ноль!\n");
        return 0; 
    }
    return a / b;
}
