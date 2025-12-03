#include <stdio.h>
#include <stdlib.h>

int GetSet(int **a)
{
    int n, i;
    int *arr;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1) {
        printf("No number!\n");
        return 0;
    }

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        return 0;
    }

    for (i = 0; i < n; i++) {
        printf("Enter Number %d: ", i + 1);
        if (scanf("%d", &arr[i]) != 1) {
            printf("No number!\n");
            free(arr);
            return 0;
        }
    }

    *a = arr;
    return n;
}

int main()
{
    int *data, num;
    int i;

    num = GetSet(&data);

    printf("\n--- Result ---\n");
    for (i = 0; i < num; i++) {
        printf("data[%d] = %d\n", i, data[i]);
    }

    free(data);
    return 0;
}