#include <stdio.h>

void Addition(int a, int b)
{
    int add = (a + b);
    printf("Result: %d", add);
}

void Subtraction(int a, int b)
{
    int sub = (a - b);
    printf("Result: %d", sub);
}

void Multiplication(int a, int b)
{
    int multi = (a * b);
    printf("Result: %d", multi);
}

void Division(int a, int b)
{
    double div = (a / b);
    printf("Result: %lf", div);
}

int main()
{
    int choice;
    int num1, num2;

    while(1)
    {
        printf("\nSelect an operation:\n1)Addition(+)\n2)Subtraction(-)\n3)Multiplication(*)\n4)Division(/)\n5)Exit\n");
        scanf("%d", &choice);
        if (choice == 5)
        {
            break;
        }
        printf("Select first number: ");
        scanf("%d", &num1);
        printf("Select second number: ");
        scanf("%d", &num2);
        switch (choice)
        {
        case 1:
            Addition(num1, num2);
            break;
        case 2:
            Subtraction(num1, num2);
            break;
        case 3:
            Multiplication(num1, num2);
            break;
        case 4:
            Division(num1, num2);
            break;
        default:
            printf("Wrong choice");
            break;
        }
    }
}