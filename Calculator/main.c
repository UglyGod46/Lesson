#include "Operations.h"


int main() {
    int current_size = 0;
    Command new_command;

    Create_command("Сложение", Addition, &new_command);
    current_size = Add_to_massive(new_command, commands, current_size);
    Create_command("Вычитание", Subtraction, &new_command);
    current_size = Add_to_massive(new_command, commands, current_size);
    Create_command("Умножение", Multiplication, &new_command);
    current_size = Add_to_massive(new_command, commands, current_size);
    Create_command("Деление", Division, &new_command);
    current_size = Add_to_massive(new_command, commands, current_size);

    int choice;
    while (1) {
        printf("\nВыберите операцию:\n");
        for (int i = 0; i < current_size; i++) {
            printf("%d. %s\n", i + 1, commands[i].name);
        }
        printf("0. Выход\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }

        if (choice < 1 || choice > current_size) {
            printf("Неверный выбор, попробуйте снова.\n");
            continue;
        }

        int num_args;
        printf("Введите количество аргументов: ");
        scanf("%d", &num_args);

        if (num_args <= 0) {
            printf("Количество аргументов должно быть больше нуля.\n");
            continue;
        }

        double *args = malloc(num_args * sizeof(double));
        printf("Введите аргументы:\n");
        for (int i = 0; i < num_args; i++) {
            scanf("%lf", &args[i]);
        }

        double result = commands[choice - 1].func(num_args, args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9]); 
        printf("Результат: %lf\n", result);
        free(args);
    }

    return 0;
}
