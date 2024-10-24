#define MAX_MASSIVE_LENGTH 100
#define POSITION_LENGTH 50
#define PHONE_LENGTH 15

typedef struct
{
    char firstName[MAX_MASSIVE_LENGTH];
    char lastName[MAX_MASSIVE_LENGTH];
    char workPlace[MAX_MASSIVE_LENGTH];
    char post[POSITION_LENGTH];
    char phoneNumber[PHONE_LENGTH];
    char email[MAX_MASSIVE_LENGTH];
    char social[MAX_MASSIVE_LENGTH];
} Contact;

Contact contacts[MAX_MASSIVE_LENGTH];
int contactCount = 0;

void AddContact();

void DeleteContact();

void EditContact();

void ListContacts();