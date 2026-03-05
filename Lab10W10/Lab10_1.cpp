#include <stdio.h>

/* prototype */
long SumLoop(int);
long SumRecur(int);

/* main */
int main() {

    printf("SumLoop(n) = %ld\n", SumLoop(10));
    printf("SumRecur(n) = %ld\n", SumRecur(10));

    return 0;
}

/* function แบบ loop */
long SumLoop(int n) {

    long sum = 0;
    int i;

    for(i = 1; i <= n; i++) {
        sum = sum + i;
    }

    return sum;
}

/* function แบบ recursion */
long SumRecur(int n) {

    if(n == 1)      // base case
        return 1;

    return n + SumRecur(n - 1);
}