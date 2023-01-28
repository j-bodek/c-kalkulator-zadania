#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{

    // sprawdź czy podano scieżke pliku
    if (argc < 2)
    {
        printf("Nie podano scieżki pliku\nUzycie: %s <plik wejsciowy>\n", argv[0]);
        return 0;
    }

    FILE *file = fopen(argv[1], "r");
    // sprawdź czy udało sie otworzyć plik
    if (file == NULL)
    {
        printf("Nie można otworzyć pliku, %s\n", strerror(errno));
        return 0;
    }

    // przejdź na koniec pliku
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    // wroc do poczatku pliku
    fseek(file, 0, SEEK_SET);
    // jesli plik jest pusty zamknij go
    if (file_size == 0)
    {
        printf("Plik jest pusty");
        return 0;
    }

    // inicjalizacja tablicy przechowywujacej ilość wystapień każdego znaku ascii
    int ascii_array[128] = {0};
    // maksymalna dlugość lini 255 znakow (ostatni element tablicy jest uzywany do oznaczenia jej konca)
    char line[256];

    // czytaj linijke (o maksymalnej dlugości 255)
    while (fgets(line, sizeof(line), file))
    {
        // iteracja przez każdy znak linijki
        for (int i = 0; i < strlen(line); i++)
        {
            // inkrementacja wartości wystąpień znaku o danym indeksie
            ascii_array[line[i]]++;
        };
    };

    // zamknij plik
    fclose(file);

    // wyświetl ilość wystąpień poszczególnych znaków
    for (int i = 0; i < 128; i++)
    {
        // wyświetl znak i ilość wystąpień (jeśli ilość wystąpień większa od zera)
        if (ascii_array[i] != 0)
        {
            printf("%c - %d\n", i, ascii_array[i]);
        }
    }

    return 0;
}
