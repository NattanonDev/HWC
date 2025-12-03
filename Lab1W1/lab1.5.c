#include <stdio.h>
#include <stdlib.h>

void GetMatrix(int **value, int *row, int *col)
{
    int r, c, i;
    int *arr;

    printf("Enter number of rows: ");
    if (scanf("%d", &r) != 1) {
        printf("No number!\n");
        return;
    }

    printf("Enter number of columns: ");
    if (scanf("%d", &c) != 1) {
        printf("No number!\n");
        return;
    }

    arr = (int *)malloc(r * c * sizeof(int));
    if (arr == NULL) {
        return;
    }

    for (i = 0; i < r * c; i++) {
        printf("Enter value %d: ", i + 1);
        if (scanf("%d", &arr[i]) != 1) {
            printf("No number!\n");
            free(arr);
            return;
        }
    }

    *value = arr;
    *row = r;
    *col = c;
}

int main()
{
    int *data, m, n;
    int i;

    GetMatrix(&data, &m, &n);

    printf("\n--- Result ---\n");
    for (i = 0; i < m * n; i++) {
        printf("data[%d] = %d\n", i, data[i]);
    }

    free(data);
    return 0;
}