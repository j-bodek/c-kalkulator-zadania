#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <errno.h>

int isNumber(char s[])
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (isdigit(s[i]) == 0)
            return 0;
    }
    return 1;
}

int *generateArray(int length)
{
    srand(time(NULL));
    int *array = (int *)malloc(length * sizeof(int));

    int i;
    for (i = 0; i < length; i++)
    {
        array[i] = rand();
    }

    return array;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Nieprawidlowa ilosc argumentow. Podaj: dlugosc_tablicy sciezka_pliku\n");
        return 0;
    }

    if (!isNumber(argv[1]))
    {
        printf("Argument <dlugosc_tablicy> %s nie jest liczba.", argv[1]);
        return 0;
    }

    int array_len = atoi(argv[1]);
    long double product = 1;
    int *array = generateArray(array_len);

    printf("Tablica - {");
    for (int i = 0; i < array_len; i++)
    {
        printf("%d", array[i]);
        if (array[i] % 2 != 0)
        {
            product *= array[i];
        }
        if (i != array_len - 1)
        {
            printf(",");
        }
    }
    printf("}\n");
    printf("Iloczyn: %Lf", product);

    FILE *file = fopen(argv[2], "w");

    if (file == NULL)
    {
        perror("Nie mozna otworzyc pliku.");
        return 0;
    }

    fprintf(file, "Tablica - {");
    for (int i = 0; i < array_len; i++)
    {
        fprintf(file, "%d", array[i]);
        if (i != array_len - 1)
        {
            fprintf(file, ",");
        }
    }
    fprintf(file, "}\n");
    fprintf(file, "Iloczyn: %Lf", product);

    fclose(file);
    free(array);
    return 0;
}