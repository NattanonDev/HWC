#include <stdio.h>

#define MAX_SIZE 10
#define UNVISITED 0
#define VISITED 1

int main() {
    int data[MAX_SIZE];
    int status[MAX_SIZE];
    int N;
    int i, j;
    int count;

    /* กำหนดสถานะเริ่มต้นให้ยังไม่ถูกนับ */
    for (i = 0; i < MAX_SIZE; i++) {
        status[i] = UNVISITED;
    }

    /* รับค่า N */
    scanf("%d", &N);

    if (N > MAX_SIZE || N < 1) {
        N = MAX_SIZE;
    }

    /* รับตัวเลข N ตัว */
    for (i = 0; i < N; i++) {
        scanf("%d", &data[i]);
    }

    /* รายงานข้อมูลที่รับมา */
    printf("--- FREQUENCY ANALYSIS REPORT ---\n");
    printf("Total elements recorded (N): %d\n", N);

    printf("Recorded Numbers: ");
    for (i = 0; i < N; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    /* ตารางความถี่ */
    printf("--- FREQUENCY TABLE ---\n");
    printf("Number | Frequency\n");
    printf("-------|----------\n");

    /* นับความถี่ของแต่ละตัวเลข */
    for (i = 0; i < N; i++) {

        /* ถ้าตำแหน่งนี้ถูกนับไปแล้ว ข้าม */
        if (status[i] == VISITED) {
            continue;
        }

        count = 1;          /* นับตัวเอง */
        status[i] = VISITED;

        for (j = i + 1; j < N; j++) {
            if (data[i] == data[j]) {
                count++;
                status[j] = VISITED;
            }
        }

        printf("%d | %d\n", data[i], count);
    }

    return 0;
}