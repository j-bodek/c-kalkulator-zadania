#include <stdio.h>
#include <errno.h>
#include <string.h>

char HISTORY_FILE[] = "history.bin";

void update_history(const char *log)
{
    FILE *history = fopen(HISTORY_FILE, "ab");
    if (history == NULL)
    {
        perror("Nie mozna otworzyc historii.");
        return;
    }

    char log_len = strlen(log);
    fwrite(log, sizeof(char), log_len, history);

    fclose(history);
}

void read_history()
{
    FILE *history = fopen(HISTORY_FILE, "rb");
    if (history == NULL)
    {
        perror("Nie mozna otworzyc historii.");
        return;
    }

    char line[1024];
    unsigned int line_id = 0;
    printf("\nHISTORIA OPERACJI:\n");
    while (fgets(line, sizeof(line), history) != NULL)
    {
        char line_log[4096];
        sprintf(line_log, "ID %u : ", ++line_id);
        strcat(line_log, line);
        printf("%s", line_log);
    }

    fclose(history);
}

void delete_history_execute(int operation_id)
{
    if (operation_id < 1)
    {
        printf("Nie prawidlowe ID operacji (%d)\n", operation_id);
        return;
    }

    FILE *history = fopen(HISTORY_FILE, "rb");
    if (history == NULL)
    {
        perror("Nie mozna otworzyc historii.");
        return;
    }
    FILE *new_history = fopen("new_history.bin", "w");

    char line[1024];
    unsigned int line_id = 1;
    int deleted = 0;
    while (fgets(line, sizeof(line), history) != NULL)
    {
        if (line_id != operation_id)
        {
            fputs(line, new_history);
        }
        else
        {
            deleted = 1;
            printf("\nUsunieto operacje ID: %d:\n%s", operation_id, line);
        }
        ++line_id;
    }

    fclose(history);
    fclose(new_history);
    remove(HISTORY_FILE);
    rename("new_history.bin", HISTORY_FILE);

    if (deleted == 0)
    {
        printf("Nie prawidlowe ID operacji (%d)\n", operation_id);
    }
}

void delete_history()
{
    int operation_id;
    printf("\nPodaj ID operacji: ");
    scanf("%d", &operation_id);
    delete_history_execute(operation_id);
}