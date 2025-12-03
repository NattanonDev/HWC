#include <stdio.h>

void GetSet(int data[], int *num);

int main()
{
    int data[100];
    int num;

    GetSet(data, &num);

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

    printf("\nYour numbers are:\n");
    for (i = 0; i < *num; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}
