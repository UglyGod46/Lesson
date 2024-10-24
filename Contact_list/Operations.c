#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Operations.h"


void AddContact()
{
    if(contactCount >= MAX_MASSIVE_LENGTH)
    {
        printf("The list is full");
        return;
    }

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

    printf("Contact added");
    contacts[contactCount++] = newContact;
}

void DeleteContact()
{
    char lastName[MAX_MASSIVE_LENGTH];
    printf("Input last name for delete contact: ");
    scanf("%s", lastName);

    for (int i = 0; i < contactCount; i++) 
    {
        if (strcmp(contacts[i].lastName, lastName) == 0) 
        {
            for (int j = i; j < contactCount - 1; j++) 
            {
                contacts[j] = contacts[j + 1];
            }
            contactCount--;
            printf("Contact deleated\n");
            return;
        }
    }
    printf("Contact not found\n");
}

void EditContact() 
{
    char lastName[MAX_MASSIVE_LENGTH];
    printf("Input last name for edit contact: ");
    scanf("%s", lastName);

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].lastName, lastName) == 0) 
        {
            printf("Editing a contact: %s %s\n", contacts[i].firstName, contacts[i].lastName);

            printf("Input new first name (leave it empty to save): ");
            char temp[MAX_MASSIVE_LENGTH];
            scanf(" %[^\n]s", temp);
            if (strlen(temp) > 0) 
            {
                strcpy(contacts[i].firstName, temp);
            }

            printf("Input new last name (leave it empty to save): ");
            scanf(" %[^\n]s", temp);
            if (strlen(temp) > 0) 
            {
                strcpy(contacts[i].lastName, temp);
            }

            printf("Input new work place (leave it empty to save): ");
            scanf(" %[^\n]s", temp);
            if (strlen(temp) > 0) 
            {
                strcpy(contacts[i].workPlace, temp);
            }

            printf("Input new post (leave it empty to save): ");
            scanf(" %[^\n]s", temp);
            if (strlen(temp) > 0) 
            {
                strcpy(contacts[i].post, temp);
            }

            printf("Input new phone number (leave it empty to save): ");
            scanf(" %[^\n]s", temp);
            if (strlen(temp) > 0) 
            {
                strcpy(contacts[i].phoneNumber, temp);
            }

            printf("Input new email (leave it empty to save): ");
            scanf(" %[^\n]s", temp);
            if (strlen(temp) > 0) 
            {
                strcpy(contacts[i].email, temp);
            }

            printf("Input new social link (leave it empty to save): ");
            scanf(" %[^\n]s", temp);
            if (strlen(temp) > 0) 
            {
                strcpy(contacts[i].social, temp);
            }
            
            printf("Contact updated\n");
            return;
        }
    }
    printf("Contact not found\n");
}

void ListContacts() 
{
    if (contactCount == 0) 
    {
        printf("Contact list is empty\n");
        return;
    }

    for (int i = 0; i < contactCount; i++) 
    {
        printf("%d. %s %s\n", i + 1, contacts[i].firstName, contacts[i].lastName);
        printf("   Work place: %s\n", contacts[i].workPlace);
        printf("   Post: %s\n", contacts[i].post);
        printf("   Phone number: %s\n", contacts[i].phoneNumber);
        printf("   Email: %s\n", contacts[i].email);
        printf("   Social: %s\n\n", contacts[i].social);
    }
}