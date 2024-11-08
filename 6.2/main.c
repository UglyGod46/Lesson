#include "Operations.h"
#include <dlfcn.h>

int main() {
    void* handle = dlopen("./lib.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    void (*AddContact)();
    void (*DeleteContact)();
    void (*EditContact)();
    void (*ListContacts)();
    void (*FreeList)();

    AddContact = dlsym(handle, "AddContact");
    DeleteContact = dlsym(handle, "DeleteContact");
    EditContact = dlsym(handle, "EditContact");
    ListContacts = dlsym(handle, "ListContacts");
    FreeList = dlsym(handle, "FreeList");
    if (!AddContact || !DeleteContact || !EditContact || !ListContacts || !FreeList) {
        fprintf(stderr, "%s\n", dlerror());
        dlclose(handle);
        exit(EXIT_FAILURE);
    }
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
                FreeList();
                dlclose(handle);
                return 0;
            default:
                printf("Wrong choice. Try again.\n");
        }
    }
    dlclose(handle);
    return 0;
}
