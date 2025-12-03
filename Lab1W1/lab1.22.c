#include <stdio.h>
#include <stdlib.h>

void GetSet(int a[], int *n)
{
    int i;

    printf("Enter number of elements: ");
    if (scanf("%d", n) != 1) {
        printf("No number goodbye!\n");
        return;
    }

    for (i = 0; i < *n; i++) {
        printf("Enter Number %d: ", i + 1);
        if (scanf("%d", &a[i]) != 1) {
            printf("No number goodbye!\n");
            return;
        }
    }

    printf("\nYour numbers are:\n");
    for (i = 0; i < *n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int *data, num;

    data = (int *)malloc(100 * sizeof(int));

    GetSet(data, &num);

    free(data);
    return 0;
}
