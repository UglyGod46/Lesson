#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"


void AddContact()
{
    if(contactCount >= MAX_CONTACTS)
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
    return;
}

void EditContact() 
{
    return;
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