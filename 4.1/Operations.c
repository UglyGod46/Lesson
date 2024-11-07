#include "Operations.h"


static Node* head = NULL; 
static Node* tail = NULL; 

void AddContact() {
    Contact newContact;

    printf("Input first name: \n");
    scanf("%s", newContact.firstName);
    printf("Input last name: \n");
    scanf("%s", newContact.lastName);
    printf("Input work place(if there is): \n");
    scanf("%s", newContact.workPlace);
    printf("Input post(if there is): \n");
    scanf("%s", newContact.post);
    printf("Input phone number(if there is): \n");
    scanf("%s", newContact.phoneNumber);
    printf("Input email(if there is): \n");
    scanf("%s", newContact.email);
    printf("Input social network(if there is): \n");
    scanf("%s", newContact.social);

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->contact = newContact;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        Node* current = head;
        while (current != NULL && strcmp(current->contact.lastName, newContact.lastName) < 0) {
            current = current->next;
        }

        if (current == head) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        } else if (current == NULL) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else {
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev->next = newNode;
            current->prev = newNode;
        }
    }

    printf("Contact added\n");
}

void DeleteContact() {
    char lastName[MAX_MASSIVE_LENGTH];
    printf("Input last name for delete contact: ");
    scanf("%s", lastName);

    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->contact.lastName, lastName) == 0) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                head = current->next; // Удаляем голову
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev; // Удаляем хвост
            }

            free(current);
            printf("Contact deleted\n");
            return;
        }
        current = current->next;
    }
    printf("Contact not found\n");
}

void EditContact() {
    char lastName[MAX_MASSIVE_LENGTH];
    printf("Input last name for edit contact: ");
    scanf("%s", lastName);

    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->contact.lastName, lastName) == 0) {
            printf("Editing a contact: %s %s\n", current->contact.firstName, current->contact.lastName);
            
            printf("Input new first name (leave it empty to save): ");
            char temp[MAX_MASSIVE_LENGTH];
            scanf(" %[^\n]s", temp);
            if (strlen(temp) > 0) {
                strcpy(current->contact.firstName, temp);
            }

            printf("Input new last name (leave it empty to save): ");
            scanf(" %[^\n]s", temp);
            if (strlen(temp) > 0) {
                strcpy(current->contact.lastName, temp);
            }

            printf("Input new work place (leave it empty to save): ");
            scanf(" %[^\n]s", temp);
            if (strlen(temp) > 0) {
                strcpy(current->contact.workPlace, temp);
            }

            printf("Input new post (leave it empty to save): ");
            scanf(" %[^\n]s", temp);
            if (strlen(temp) > 0) {
                strcpy(current->contact.post, temp);
            }

            printf("Input new phone number (leave it empty to save): ");
            scanf(" %[^\n]s", temp);
            if (strlen(temp) > 0) {
                strcpy(current->contact.phoneNumber, temp);
            }

            printf("Input new email (leave it empty to save): ");
            scanf(" %[^\n]s", temp);
            if (strlen(temp) > 0) {
                strcpy(current->contact.email, temp);
            }

            printf("Input new social link (leave it empty to save): ");
            scanf(" %[^\n]s", temp);
            if (strlen(temp) > 0) {
                strcpy(current->contact.social, temp);
            }

            printf("Contact updated\n");
            return;
        }
        current = current->next;
    }
    printf("Contact not found\n");
}

void ListContacts() {
    if (head == NULL) {
        printf("Contact list is empty\n");
        return;
    }

    Node* current = head;
    while (current != NULL) {
        printf("%s %s\n", current->contact.firstName, current->contact.lastName);
        printf("   Work place: %s\n", current->contact.workPlace);
        printf("   Post: %s\n", current->contact.post);
        printf("   Phone number: %s\n", current->contact.phoneNumber);
        printf("   Email: %s\n", current->contact.email);
        printf("   Social: %s\n\n", current->contact.social);
        current = current->next;
    }
}

void FreeList() {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}
