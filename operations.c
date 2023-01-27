#include <stdio.h>
#include <math.h>

#include "history.c"

void addition()
{
    double a, b;
    printf("\n---DODAWANIE---\n");
    printf("\nPodaj dwie liczby: ");

    scanf("%lf %lf", &a, &b);

    char *str_operation;
    asprintf(&str_operation, "%lf + %lf = %lf\n", a, b, a + b);
    printf("Wynik: %s", str_operation);
    update_history(str_operation);
    free(str_operation);

    printf("\n------------------------\n");
}
void subtraction()
{
    double a, b;
    printf("\n---ODEJMOWANIE---\n");
    printf("\nPodaj dwie liczby: ");

    scanf("%lf %lf", &a, &b);

    char *str_operation;
    asprintf(&str_operation, "%lf - %lf = %lf\n", a, b, a - b);
    printf("Wynik: %s", str_operation);
    update_history(str_operation);
    free(str_operation);

    printf("\n------------------------\n");
}

void multiplication()
{
    double a, b;
    printf("\n---MNOZENIE---\n");

    printf("\nPodaj dwie liczby: ");
    scanf("%lf %lf", &a, &b);

    char *str_operation;
    asprintf(&str_operation, "%lf * %lf = %lf\n", a, b, a * b);
    printf("Wynik: %s", str_operation);
    update_history(str_operation);
    free(str_operation);

    printf("\n------------------------\n");
}

void division()
{
    double a, b;
    printf("\n---DZIELENIE---\n");

    printf("\nPodaj dwie liczby: ");
    scanf("%lf %lf", &a, &b);

    char *str_operation;
    asprintf(&str_operation, "%lf / %lf = %lf\n", a, b, a / b);
    printf("Wynik: %s", str_operation);
    update_history(str_operation);
    free(str_operation);

    printf("\n------------------------\n");
}

void modulo()
{
    int a, b;
    printf("\n---MODULO---\n");

    printf("\nPodaj dwie liczby: ");
    scanf("%d %d", &a, &b);

    char *str_operation;
    asprintf(&str_operation, "%d %% %d = %d\n", a, b, a % b);
    printf("Wynik: %s", str_operation);
    update_history(str_operation);
    free(str_operation);

    printf("\n------------------------\n");
};
void factorial()
{
    int a, factorial;
    printf("\n---SILNIA---\n");

    printf("\nPodaj liczbe: ");
    scanf("%d", &a);

    factorial = 1;
    for (int i = 1; i <= a; i++)
    {
        factorial = factorial * i;
    }

    char *str_operation;
    asprintf(&str_operation, "%d! = %d\n", a, factorial);
    printf("Wynik: %s", str_operation);
    update_history(str_operation);
    free(str_operation);

    printf("\n------------------------\n");
};
void absValue()
{
    int a;
    printf("\n---WARTOSC BEZWZGLEDNA---\n");

    printf("\nPodaj liczbe: ");
    scanf("%d", &a);

    char *str_operation;
    asprintf(&str_operation, "|%d| = %d\n", a, abs(a));
    printf("Wynik: %s", str_operation);
    update_history(str_operation);
    free(str_operation);

    printf("\n------------------------\n");
};
void power()
{
    double a, b;
    printf("\n---POTEGOWANIE---\n");

    printf("\nPodaj dwie liczby (podstawa, wykladnik): ");
    scanf("%lf %lf", &a, &b);

    char *str_operation;
    asprintf(&str_operation, "%lf^%lf = %lf\n", a, b, pow(a, b));
    printf("Wynik: %s", str_operation);
    update_history(str_operation);
    free(str_operation);

    printf("\n------------------------\n");
};
void logarithm10()
{
    double a;
    printf("\n---LOGARYTM DZIESIETNY---\n");

    printf("\nPodaj liczbe: ");
    scanf("%lf", &a);

    char *str_operation;
    asprintf(&str_operation, "log10(%lf) = %lf\n", a, log10(a));
    printf("Wynik: %s", str_operation);
    update_history(str_operation);
    free(str_operation);

    printf("\n------------------------\n");
};
void squareroot()
{
    double a;
    printf("\n---PIERWIASTEK KWADRATOWY---\n");

    printf("\nPodaj liczbe: ");
    scanf("%lf", &a);

    char *str_operation;
    asprintf(&str_operation, "%lf^0.5 = %lf\n", a, sqrt(a));
    printf("Wynik: %s", str_operation);
    update_history(str_operation);
    free(str_operation);

    printf("\n------------------------\n");
};