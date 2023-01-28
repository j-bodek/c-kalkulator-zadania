#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "operations.c"
#include "help.c"

int main()
{
    printf("KALKULATOR");
    help();

    char operation[10];
    while (1)
    {

        printf("\nOperacja: ");
        scanf(" %10s", operation);

        if (!strcmp(operation, "help"))
        {
            help();
        }
        else if (!strcmp(operation, "exit"))
        {
            exit(0);
        }
        else if (!strcmp(operation, "+"))
        {
            addition();
        }
        else if (!strcmp(operation, "-"))
        {
            subtraction();
        }
        else if (!strcmp(operation, "*"))
        {
            multiplication();
        }
        else if (!strcmp(operation, "/"))
        {
            division();
        }
        else if (!strcmp(operation, "%"))
        {
            modulo();
        }
        else if (!strcmp(operation, "!"))
        {
            factorial();
        }
        else if (!strcmp(operation, "abs"))
        {
            absValue();
        }
        else if (!strcmp(operation, "pow"))
        {
            power();
        }
        else if (!strcmp(operation, "log"))
        {
            logarithm10();
        }
        else if (!strcmp(operation, "sqrt"))
        {
            squareroot();
        }
        else if (!strcmp(operation, "history"))
        {
            read_history();
        }
        else if (!strcmp(operation, "delete"))
        {
            delete_history();
        }
        else
        {
            printf("\nNieprawidlowa operacja '%s'.\nWywolaj <help> zeby zobaczyc dostepne operacje.\n", operation);
        }
    }

    return 0;
}