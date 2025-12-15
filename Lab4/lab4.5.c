#include <stdio.h>
#define SIZE 6

int main() {
    int data[SIZE];
    int total_sum = 0;
    int i;

    // รับค่าตัวเลขจำนวนเต็ม 6 ตัว
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &data[i]);
    }

    // คำนวณผลรวมของตัวเลขทั้งหมด
    for (i = 0; i < SIZE; i++) {
        total_sum = total_sum + data[i];
    }

    // แสดงรายงานผล
    printf("--- SUMMATION REPORT ---\n");
    printf("Recorded Numbers: ");

    for (i = 0; i < SIZE; i++) {
        printf("%d ", data[i]);
    }

    printf("\n");
    printf("Total Sum of Numbers: %d\n", total_sum);

    return 0;
}