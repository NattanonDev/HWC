#include <stdio.h>   // Include standard input/output library

int main() {
    int num1, num2, operationCode, result;

    // Read two numbers and the operation code
    // If the input does not match exactly 3 integers, stop the program
    if (scanf("%d %d %d", &num1, &num2, &operationCode) != 3) {
        return 1;
    }

    /*
        Use switch-case to determine the operation:
        1 = addition
        2 = subtraction
        3 = multiplication
        4 = division
        other values = invalid operation
    */
    switch (operationCode) {
        case 1:
            // Addition
            result = num1 + num2;
            printf("%d", result);
            break;

        case 2:
            // Subtraction
            result = num1 - num2;
            printf("%d", result);
            break;

        case 3:
            // Multiplication
            result = num1 * num2;
            printf("%d", result);
            break;

        case 4:
            // Division (integer division)
            result = num1 / num2;
            printf("%d", result);
            break;

        default:
            // Invalid menu code
            printf("Invalid Operation");
            break;
    }

    return 0;   // End of program
}
