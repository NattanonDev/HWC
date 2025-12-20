#include <stdio.h>

#define ROWS 2
#define COLS 4

int main() {
    int matrix[ROWS][COLS];
    int total_sum = 0;
    int i, j;

    /* รับค่าจำนวนเต็มทั้งหมด 8 ค่า เก็บลง matrix 2x4 */
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    /* คำนวณผลรวมของทุกช่องใน matrix */
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            total_sum = total_sum + matrix[i][j];
        }
    }

    /* แสดงรายงาน */
    printf("--- 2D ARRAY SUMMATION REPORT ---\n");
    printf("Recorded Matrix (2x4):\n");

    /* แสดง matrix เป็นตาราง */
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (j == COLS - 1) {
                printf("%d", matrix[i][j]);     /* ตัวสุดท้ายของแถว ไม่เว้นวรรคท้าย */
            } else {
                printf("%d ", matrix[i][j]);
            }
        }
        printf("\n");
    }

    printf("\n");
    printf("Total Sum of all elements: %d\n", total_sum);

    return 0;
}