#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isNumber(char s[])
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (isdigit(s[i]) == 0)
            return 0;
    }
    return 1;
}

void count_digits(char *number)
{
    if (isNumber(number))
    {
        printf("Liczba ma %lu cyfr/e", strlen(number));
    }
    else
    {
        printf("'%s' nie jest liczba", number);
    }
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        count_digits(argv[1]);
    }
    else if (argc > 2)
        printf("Za duzo argumentow\n");
    else
        printf("Nie wprowadzono zadnej liczby\n");

    return 0;
}