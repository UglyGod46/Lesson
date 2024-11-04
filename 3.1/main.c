#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

void print_permissions(mode_t mode) {
    printf("Битовое представление прав доступа: ");
    printf((mode & S_IRUSR) ? "r" : "-");
    printf((mode & S_IWUSR) ? "w" : "-");
    printf((mode & S_IXUSR) ? "x" : "-");
    printf((mode & S_IRGRP) ? "r" : "-");
    printf((mode & S_IWGRP) ? "w" : "-");
    printf((mode & S_IXGRP) ? "x" : "-");
    printf((mode & S_IROTH) ? "r" : "-");
    printf((mode & S_IWOTH) ? "w" : "-");
    printf((mode & S_IXOTH) ? "x" : "-");
    printf("\n");
}

mode_t parse_permissions(const char *input) {
    mode_t mode = 0;

    if (strlen(input) == 3) { 
        mode = (input[0] - '0') * 64 + (input[1] - '0') * 8 + (input[2] - '0');
    } else if (strlen(input) == 9) { 
        for (int i = 0; i < 3; i++) {
            if (input[i * 3] == 'r') mode |= (S_IRUSR >> (i * 3));
            if (input[i * 3 + 1] == 'w') mode |= (S_IWUSR >> (i * 3));
            if (input[i * 3 + 2] == 'x') mode |= (S_IXUSR >> (i * 3));
        }
    }
    return mode;
}

void display_file_permissions(const char *filename) {
    struct stat fileStat;

    if (stat(filename, &fileStat) < 0) {
        perror("Ошибка получения информации о файле");
        return;
    }

    printf("Права доступа к файлу '%s':\n", filename);
    print_permissions(fileStat.st_mode);
}

int main() {
    char input[10];
    char filename[256];

    while (1) {
        printf("Введите права доступа (буквенное или цифровое) или 'exit' для выхода: ");
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) break;

        mode_t mode = parse_permissions(input);
        printf("Цифровое представление прав доступа: %03o\n", mode);
        print_permissions(mode);

        printf("Введите имя файла для получения прав доступа: ");
        scanf("%s", filename);
        display_file_permissions(filename);

        printf("Введите новые права доступа (буквенное или цифровое) для изменения: ");
        scanf("%s", input);
        mode = parse_permissions(input);
        printf("Обновленные права доступа:\n");
        printf("Цифровое представление: %03o\n", mode);
        print_permissions(mode);
    }

    return 0;
}
