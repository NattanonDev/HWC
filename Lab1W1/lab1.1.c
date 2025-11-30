#include <stdio.h>

int main() {
    int n, i;

    if (scanf("%d", &n) != 1) {
        return 1;
    }

    for (i = 1; i <= n; i++) {
        printf("[%d] Hello world\n", i);
    }

    return 0;
}