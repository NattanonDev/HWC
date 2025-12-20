#include <stdio.h>

void swap_value(int *a, int *b);

int main() {
    int num1;
    int num2;

    printf("Enter value for Num1: ");
    scanf("%d", &num1);

    printf("Enter value for Num2: ");
    scanf("%d", &num2);

    printf("\n--- SWAPPING REPORT ---\n");
    printf("Before Swap - Num1: %d, Num2: %d\n", num1, num2);

    swap_value(&num1,&num2);

    printf("After Swap - Num1: %d, Num2: %d\n", num1, num2);

    return 0;
}

void increase_value(int *number_ptr) {
    *number_ptr = *number_ptr + 10;
}