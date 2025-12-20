#include <stdio.h>
#define STUDENTS 5

int main() {
    int scores[STUDENTS];
    int sum = 0;
    float average = 0.0;
    int above_average_count = 0;
    int i;

    // รับคะแนนนักเรียน 5 คน
    for (i = 0; i < STUDENTS; i++) {
        scanf("%d", &scores[i]);
        sum = sum + scores[i];
    }

    // คำนวณค่าเฉลี่ย
    average = (float)sum / STUDENTS;

    // นับจำนวนคะแนนที่มากกว่าค่าเฉลี่ย
    for (i = 0; i < STUDENTS; i++) {
        if (scores[i] > average) {
            above_average_count++;
        }
    }

    // แสดงรายงานผล
    printf("--- STUDENT SCORE ANALYSIS REPORT ---\n");
    printf("Recorded Scores: ");
    for (i = 0; i < STUDENTS; i++) {
        printf("%d ", scores[i]);
    }

    printf("\n");
    printf("Total Sum: %d\n", sum);
    printf("Average Score: %.2f\n", average);
    printf("Number of Scores Above Average: %d\n", above_average_count);

    return 0;
}