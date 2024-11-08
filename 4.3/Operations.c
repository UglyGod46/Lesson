#include "Operations.h"

TreeNode* root = NULL; 

TreeNode* CreateNode(Contact contact) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->contact = contact;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void AddContact() {
    Contact newContact;
    printf("Введите имя: \n");
    scanf("%s", newContact.firstName);
    printf("Введите фамилию: \n");
    scanf("%s", newContact.lastName);
    printf("Введите место работы: \n");
    scanf("%s", newContact.workPlace);
    printf("Введите должность: \n");
    scanf("%s", newContact.post);
    printf("Введите номер телефона: \n");
    scanf("%s", newContact.phoneNumber);
    printf("Введите эл. почту: \n");
    scanf("%s", newContact.email);
    printf("Введите соц. сети: \n");
    scanf("%s", newContact.social);
    TreeNode* newNode = CreateNode(newContact);
    if (root == NULL) {
        root = newNode;
    } else {
        TreeNode* current = root;
        TreeNode* parent = NULL;
        while (1) {
            parent = current;
            if (strcmp(newContact.lastName, current->contact.lastName) < 0) {
                current = current->left;
                if (current == NULL) {
                    parent->left = newNode;
                    return;
                }
            } else {
                current = current->right;
                if (current == NULL) {
                    parent->right = newNode;
                    return;
                }
            }
        }
    }
    printf("Контакт добавлен\n");
}
TreeNode* FindMin(TreeNode* node) {
    while (node && node->left != NULL) {
        node = node->left;
    }
    return node;
}
TreeNode* DeleteNode(TreeNode* root, char* lastName) {
    if (root == NULL) return root;
    if (strcmp(lastName, root->contact.lastName) < 0) {
        root->left = DeleteNode(root->left, lastName);
    } else if (strcmp(lastName, root->contact.lastName) > 0) {
        root->right = DeleteNode(root->right, lastName);
    } else {
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        TreeNode* temp = FindMin(root->right);
        root->contact = temp->contact;
        root->right = DeleteNode(root->right, temp->contact.lastName);
    }
    return root;
}
void DeleteContact() {
    char lastName[MAX_MASSIVE_LENGTH];
    printf("Введите фамилию контакта, который надо удалить: ");
    scanf("%s", lastName);
    root = DeleteNode(root, lastName);
    printf("Контакт удалён\n");
}
void EditContact() {
    char lastName[MAX_MASSIVE_LENGTH];
    printf("Введите фамилию контакта, который надо изменить: ");
    scanf("%s", lastName);
    TreeNode* current = root;
    while (current != NULL) {
        if (strcmp(lastName, current->contact.lastName) == 0) {
            printf("Изменение контакта: %s %s\n", current->contact.firstName, current->contact.lastName);
            printf("Введите новое имя: ");
            char temp[MAX_MASSIVE_LENGTH];
            scanf(" %[^\n]s", temp);
            if (strlen(temp) > 0) {
                strcpy(current->contact.firstName, temp);
            }
            printf("Введите новую фамилию: ");
            scanf(" %[^\n]s", temp);
            if (strlen(temp) > 0) {
                strcpy(current->contact.lastName, temp);
            }
            printf("Введите новое место работы: ");
            scanf(" %[^\n]s", temp);
            if (strlen(temp) > 0) {
                strcpy(current->contact.workPlace, temp);
            }
            printf("Введите новую должность: ");
            scanf(" %[^\n]s", temp);
            if (strlen(temp) > 0) {
                strcpy(current->contact.post, temp);
            }
            printf("Введите новый номер телефона: ");
            scanf(" %[^\n]s", temp);
            if (strlen(temp) > 0) {
                strcpy(current->contact.phoneNumber, temp);
            }
            printf("Введите новую эл. почту: ");
            scanf(" %[^\n]s", temp);
            if (strlen(temp) > 0) {
                strcpy(current->contact.email, temp);
            }
            printf("Введите новые соц сети: ");
            scanf(" %[^\n]s", temp);
            if (strlen(temp) > 0) {
                strcpy(current->contact.social, temp);
            }
            printf("Контакт изменён\n");
            return;
        } else if (strcmp(lastName, current->contact.lastName) < 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    printf("Contact not found\n");
}

void InOrder(TreeNode* node) {
    if (node != NULL) {
        InOrder(node->left);
        printf("Имя: %s\n", node->contact.firstName);
        printf("Фамилия: %s\n", node->contact.lastName);
        printf("Место работы: %s\n", node->contact.workPlace);
        printf("Должность: %s\n", node->contact.post);
        printf("Телефон: %s\n", node->contact.phoneNumber);
        printf("Email: %s\n", node->contact.email);
        printf("Социальные сети: %s\n", node->contact.social);
        printf("---------------------\n");
        InOrder(node->right);
    }
}

void ListContacts() {
    if (root == NULL) {
        printf("Список пуст\n");
        return;
    }
    InOrder(root);
}

