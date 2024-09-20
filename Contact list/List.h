#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define WORKPLACE_LENGTH 100
#define POSITION_LENGTH 50
#define PHONE_LENGTH 15
#define EMAIL_LENGTH 100
#define SOCIAL_LENGTH 100

typedef struct
{
    char firstName[NAME_LENGTH];
    char lastName[NAME_LENGTH];
    char workPlace[WORKPLACE_LENGTH];
    char post[POSITION_LENGTH];
    char phoneNumber[PHONE_LENGTH];
    char email[EMAIL_LENGTH];
    char social[SOCIAL_LENGTH];
} Contact;

Contact contacts[MAX_CONTACTS];
int contactCount = 0;