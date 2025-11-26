#include <stdio.h>   // Include standard I/O library for scanf and printf

int main() {
    int score;       // Declare variable to store the exam score

    // Read the score from user input
    // If the input is not a valid integer, stop the program
    if (scanf("%d", &score) != 1) {
        return 1;
    }

    /* 
       Determine the grade based on the score.
       This uses cascading if-else if-else statements.
    */

    if (score >= 80) {
        // Score 80 or above
        printf("Grade A");
    }
    else if (score >= 70) {
        // Score between 70 and 79
        printf("Grade B");
    }
    else if (score >= 60) {
        // Score between 60 and 69
        printf("Grade C");
    }
    else if (score >= 50) {
        // Score between 50 and 59
        printf("Grade D");
    }
    else {
        // Score below 50
        printf("Grade F");
    }

    return 0;   // End of program
}
