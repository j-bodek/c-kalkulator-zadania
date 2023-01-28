#include <stdio.h>

char *print_bin(int bytes, void *data, char *str)
{
    for (int i = 0; i < bytes; i++)
    {
        for (int j = 0; j < 8; j++)
            str[8 * i + i + j] = ((unsigned char *)data)[i] & (1 << (7 - j)) ? '1' : '0';
        str[8 * (i + 1) + i] = ' ';
    }
    str[8 * bytes + bytes - 1] = '\0';
    return str;
}

int main()
{
    char buf[255];
    int a = 123;
    char string[] = "abcd";

    printf("123 -> %s\n", print_bin(sizeof(a), &a, buf));
    printf("'abcd' -> %s\n", print_bin(sizeof(string), &string, buf));

    return 0;
}
