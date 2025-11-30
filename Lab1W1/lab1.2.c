#include <stdio.h>
#include <stdlib.h>

void GetSet(int data[], int *n);

void GetSet(int data[], int *n) {
    int i;

    printf("Enter number of elements: ");
    scanf("%d", n);

    for (i = 0; i < *n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &data[i]);
    }
}

int main() {
    int *data, num;

    printf("Enter number of elements: ");
    scanf("%d", &num);

    data = (int *)malloc(num * sizeof(int));

    GetSet(data, &num);

    printf("\n--- Result ---\n");
    for (int i = 0; i < num; i++) {
        printf("data[%d] = %d\n", i, data[i]);
    }

    free(data);
    return 0;
}