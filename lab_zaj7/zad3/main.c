#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void *merge_arrays(void *array1, void *array2, int len1, int len2, int size_t)
{
    int combined_length = len1 + len2;
    void *merged_array = (void *)malloc(combined_length * size_t);

    int i;
    int *a = array1;
    int *b = array2;
    int *m_a = merged_array;
    for (i = 0; i < combined_length; i++)
    {
        if (i % 2 == 0)
        {
            m_a[i] = a[i / 2];
        }
        else
        {
            m_a[i] = b[(i - 1) / 2];
        }
    }

    return m_a;
}

int main()
{
    int array1[] = {1, 3, 5};
    int array2[] = {2, 4, 6};

    int len1 = sizeof(array1) / sizeof(array1[0]);
    int len2 = sizeof(array2) / sizeof(array2[0]);

    void *merged_array = merge_arrays(array1, array2, len1, len2, sizeof(array1[0]));
    int *m_a = merged_array;
    int i;
    for (i = 0; i < (len1 + len2); i++)
    {
        printf("%d", m_a[i]);
    }

    free(merged_array);
    return 1;
}