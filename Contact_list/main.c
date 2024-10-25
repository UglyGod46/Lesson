#include "Operations.h"

int main()
{
    int choice;
   
    while (1) {
        printf("\nContact list:\n");
        printf("1. Add contact\n");
        printf("2. Edit contact\n");
        printf("3. Delete contact\n");
        printf("4. Show contact list\n");
        printf("5. Exit\n");
        printf("Select action: ");
        scanf("%d", &choice);

        switch (choice) 
        {
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

