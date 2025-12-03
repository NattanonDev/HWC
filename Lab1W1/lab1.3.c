#include <stdio.h>
#include <stdlib.h>

int *GetSet(int *num);

int main()
{
    int *data;
    int num;
    int i;

    data = GetSet(&num);

    printf("\n--- Result ---\n");
    for (i = 0; i < num; i++) {
        printf("data[%d] = %d\n", i, data[i]);
    }

    free(data);
    return 0;
}

int *GetSet(int *num)
{
    int i;
    int *data;

    printf("Enter number of elements: ");
    if (scanf("%d", num) != 1) {
        printf("No number!\n");
        return NULL;
    }

    data = (int *)malloc((*num) * sizeof(int));
    if (data == NULL) {
        return NULL;
    }

    for (i = 0; i < *num; i++) {
        printf("Enter Number %d: ", i + 1);
        if (scanf("%d", &data[i]) != 1) {
            printf("No number!\n");
            free(data);
            return NULL;
        }
    }

    return data;
}
