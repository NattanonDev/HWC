#include <stdio.h>   // Include standard input/output library

int main() {
    int N, sum = 0, i;   // N = input number, sum = total sum, i = loop counter

    // Read the value of N from user input.
    // If the input is not a valid integer, exit the program.
    if (scanf("%d", &N) != 1) {
        return 1;
    }

    /*
        Calculate the sum of all numbers from 1 up to N.
        If N is 0 or negative, the loop will not run,
        and sum will remain 0 (which matches the test case requirement).
    */
    for (i = 1; i <= N; i++) {
        sum += i;   // Add i to the running total
    }

    // Display the final sum
    printf("%d\n", sum);

    return 0;   // End of program
}
