#include "Operations.h"

int main() 
{
    int choice, num_args;
    double result;

    while (1) 
    {
        printf("Выберите операцию:\n");
        printf("1) Сложение\n");
        printf("2) Вычитание\n");
        printf("3) Умножение\n");
        printf("4) Деление\n");
        printf("5) Выход\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);

        if (choice == 5) {
            break; 

        printf("Введите количество чисел для операции: ");
        scanf("%d", &num_args);

        double numbers[num_args];
        printf("Введите %d чисел:\n", num_args);
        for (int i = 0; i < num_args; i++) 
        {
            scanf("%lf", &numbers[i]);
        }

        switch (choice) 
        {
            case 1:
                result = Addition(num_args, numbers[0], numbers[1], numbers[2], numbers[3], numbers[4]); 
                printf("Результат сложения: %.2f\n", result);
                break;
            case 2:
                result = Subtraction(num_args, numbers[0], numbers[1], numbers[2], numbers[3], numbers[4]);
                printf("Результат вычитания: %.2f\n", result);
                break;
            case 3:
                result = Multiplication(num_args, numbers[0], numbers[1], numbers[2], numbers[3], numbers[4]);
                printf("Результат умножения: %.2f\n", result);
                break;
            case 4:
                result = Division(num_args, numbers[0], numbers[1], numbers[2], numbers[3], numbers[4]);
                printf("Результат деления: %.2f\n", result);
                break;
            default:
                printf("Неверный выбор. Попробуйте снова.\n");
                break;
        }
    }

    return 0;
    }
}