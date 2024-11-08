#include "Operations.h"
int main() {
    int choice;
    while (1) {
        printf("\nСписок контактов:\n");
        printf("1. Добавить контакт\n");
        printf("2. Изменить контакт\n");
        printf("3. Удалить контакт\n");
        printf("4. Вывести список контактов\n");
        printf("5. Выход\n");
        printf("Выбор действия: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                AddContact();
                break;
            case 2:
                EditContact();
                break;
            case 3:
                DeleteContact();
                break;
            case 4:
                ListContacts();
                break;
            case 5:
                return 0;
            default:
                printf("Wrong choice. Try again.\n");
        }
    }
    return 0;
}
