#include <stdio.h>
#include <stdlib.h>

int *GetSet(int *n)
{
    int i;
    int *arr;

    printf("Enter number of elements: ");
    scanf("%d", n);

    arr = (int *)malloc((*n) * sizeof(int));

    for(i = 0; i < *n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    return arr;
}

int main()
{
    int *data, num;

    data = GetSet(&num);

    return 0;
}
