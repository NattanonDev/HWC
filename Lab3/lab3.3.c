#include <stdio.h>

struct Student {
    char name[50];
    int studentId;
    float score;
};

int main() {
    int N, i;

    if (scanf("%d", &N) != 1) {
        return 1;
    }

    struct Student students[1000];
    float totalScore = 0.0;

    for (i = 0; i < N; i++) {

        if (scanf("%d %f %s", &students[i].studentId, &students[i].score, students[i].name) != 3) {
            return 1;
        }
        totalScore += students[i].score;
    }

    for (i = 0; i < N; i++) {
        printf("ID: %d, Name: %s, Score: %.2f\n", students[i].studentId, students[i].name, students[i].score);
    }

    return 0;
}