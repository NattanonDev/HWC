#include <stdio.h>

struct Student {
    int id;
    int math_score;
    int science_score;
    int english_score;
    int total_score;
};

char calculate_grade(int total_score);
void calculate_average(int total_score, float *avg);

int main() {
    struct Student student_info;
    char final_grade;
    float final_average;

    printf("Enter Student ID: ");
    scanf("%d", &student_info.id);

    printf("Enter Math Score (out of 100): ");
    scanf("%d", &student_info.math_score);

    printf("Enter Science Score (out of 100): ");
    scanf("%d", &student_info.science_score);

    printf("Enter English Score (out of 100): ");
    scanf("%d", &student_info.english_score);

    /* คำนวณคะแนนรวม */
    student_info.total_score =
        student_info.math_score +
        student_info.science_score +
        student_info.english_score;

    /* เรียกใช้ Function */
    final_grade = calculate_grade(student_info.total_score);
    calculate_average(student_info.total_score, &final_average);

    printf("\n--- STUDENT ACADEMIC REPORT ---\n");
    printf("Student ID: %d\n", student_info.id);
    printf("Math Score: %d\n", student_info.math_score);
    printf("Science Score: %d\n", student_info.science_score);
    printf("English Score: %d\n", student_info.english_score);
    printf("Total Score: %d\n", student_info.total_score);
    printf("Average Score: %.2f\n", final_average);
    printf("Final Grade: %c\n", final_grade);

    return 0;
}