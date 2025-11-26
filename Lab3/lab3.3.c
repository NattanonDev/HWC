#include <stdio.h>

struct Student {
    char name[50];
    int studentId;
    float score;
};

int main() {
    int N, i;
    int passCount = 0;
    int failCount = 0;

    if (scanf("%d", &N) != 1) {
        return 1;
    }

    struct Student students[1000];

    for (i = 0; i < N; i++) {

        if (scanf("%d %f %s", &students[i].studentId, &students[i].score, students[i].name) != 3) {
            return 1;
        }
        // totalScore += students[i].score;
    }

    // printf("Average Score: %.2f\n", totalScore / N);

    return 0;
}