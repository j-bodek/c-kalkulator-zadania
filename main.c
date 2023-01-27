#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "operations.c"

void help()
{
    printf("\n'+' - dodawanie");
    printf("\n'-' - odejmowanie");
    printf("\n'*' - mnozenie");
    printf("\n'/' - dzielenie");
    printf("\n'%%' - modulo");
    printf("\n'!' - silnia");
    printf("\n'abs' - wartosc calkowita");
    printf("\n'pow' - potegowanie");
    printf("\n'log' - logarytm dziesietny");
    printf("\n'sqrt' - pierwiastek kwadratowy");
    printf("\n'help' - wyswietl dozwolone operacje");
    printf("\n'exit' - wyjdz\n");
}

int main()
{
    char operation[10];
    while (1)
    {

        printf("\nOperacja: ");
        scanf(" %s", operation);

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
        else
        {
            printf("\nNie prawidlowa operacja '%s'.\nWywolaj <help> zeby zobaczyc dostepne operacje.\n", operation);
        }
    }

    return 0;
}