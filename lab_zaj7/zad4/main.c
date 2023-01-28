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

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    long lines;
    if (file_size != 0)
    {
        lines = 1;
    }
    else
    {
        lines = 0;
    }

    char c;
    while ((c = fgetc(file)) != EOF)
    {
        if (c == '\n')
        {
            lines++;
        }
    };

    printf("Rozmiar pliku: %ld\n", file_size);
    printf("liczba lini: %ld\n", lines);

    return 0;
}
