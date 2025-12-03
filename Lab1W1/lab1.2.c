#include <stdio.h>

void GetSet(int data[], int *num);

int main()
{
    int data[100];
    int num;
    int i;

    GetSet(data, &num);

    printf("\n--- Result ---\n");
    for (i = 0; i < num; i++) {
        printf("data[%d] = %d\n", i, data[i]);
    }

    return 0;
}

void GetSet(int data[], int *num)
{
    int i;

    printf("Enter number of elements: ");
    if (scanf("%d", num) != 1) {
        printf("No number goodbye!\n");
        return;
    }

    for (i = 0; i < *num; i++) {
        printf("Enter Number %d: ", i + 1);
        if (scanf("%d", &data[i]) != 1) {
            printf("No number goodbye!\n");
            return;
        }
    }
}