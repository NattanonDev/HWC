#include <stdio.h>

int main() {
    int N;
    int i;

    printf("number : ");
    if (scanf("%d", &N) != 1) {
        return 1;
    }

    int scores[2];

    for (i = 0; i < N; i++) {
        printf("value : ");
        if (scanf("%d", &scores[i]) != 1) {
            return 1;
        }
    }

    printf("\n");
    for (i = N - 1; i >= 0; i--) {
        printf("output : ");
        printf("%d\n", scores[i]);
    }

    return 0;
}