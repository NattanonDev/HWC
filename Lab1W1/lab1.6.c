#include <stdio.h>
#include <stdlib.h>

/* ฟังก์ชันนี้ใช้รับจำนวนแถวและคอลัมน์จากผู้ใช้
   และสร้างอาร์เรย์แบบ 1 มิติขนาด row*col
   WHY: ต้อง return pointer เพราะ main ต้องรับที่อยู่ของข้อมูลกลับไปใช้งาน */
int *GetMatrix(int *row, int *col)
{
    int r;
    int c;
    int i;

    int *matrix;   /* ตัวชี้ไปยังหน่วยความจำที่จอง */

    printf("Enter number of rows: ");
    if (scanf("%d", &r) != 1) {
        printf("No number!\n");
        return NULL;
    }

    printf("Enter number of columns: ");
    if (scanf("%d", &c) != 1) {
        printf("No number!\n");
        return NULL;
    }

    /* WHY: ต้องใช้ malloc เพราะขนาดเมทริกซ์ไม่รู้ล่วงหน้า */
    matrix = malloc(r * c * sizeof(int));
    if (matrix == NULL) {
        printf("Allocation failed.\n");
        return NULL;
    }

    /* รับค่าทีละช่องลงใน array แบบ 1 มิติ */
    for (i = 0; i < r * c; i++) {

        printf("Enter value %d: ", i + 1);

        if (scanf("%d", &matrix[i]) != 1) {
            printf("No number!\n");
            free(matrix);
            return NULL;
        }
    }

    /* ส่งค่าจำนวนแถวและคอลัมน์กลับไปยัง main */
    *row = r;
    *col = c;

    return matrix;
}

int main()
{
    int *data;
    int m;
    int n;
    int idx;

    data = GetMatrix(&m, &n);

    printf("\n--- Result ---\n");

    for (idx = 0; idx < m * n; idx++) {
        printf("data[%d] = %d\n", idx, data[idx]);
    }

    free(data);

    return 0;
}