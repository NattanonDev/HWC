#include <stdio.h>
#include <stdlib.h>

/* ฟังก์ชันนี้จะสร้างพื้นที่เก็บข้อมูลตามจำนวน row และ col ที่ผู้ใช้กำหนด 
   เลือก return เป็น pointer เพราะจำนวนสมาชิกไม่รู้ล่วงหน้า */
int *GetMatrix(int *row, int *col)
{
    int inputRow;
    int inputCol;
    int index;
    int count;
    int *buffer;

    printf("Enter number of rows: ");
    if (scanf("%d", &inputRow) != 1) {
        printf("Invalid input\n");
        return NULL;
    }

    printf("Enter number of columns: ");
    if (scanf("%d", &inputCol) != 1) {
        printf("Invalid input\n");
        return NULL;
    }

    count = inputRow * inputCol;   /* เก็บจำนวนสมาชิกทั้งหมดใน matrix */

    buffer = malloc(count * sizeof(int));
    if (buffer == NULL) {
        printf("Allocation failed\n");
        return NULL;
    }

    for (index = 0; index < count; index++) {
        printf("Enter value %d: ", index + 1);

        if (scanf("%d", &buffer[index]) != 1) {
            printf("Invalid input\n");
            free(buffer);
            return NULL;
        }
    }

    *row = inputRow;   /* ส่งค่ากลับให้ main ผ่านตัวแปร pointer */
    *col = inputCol;

    return buffer;
}

int main()
{
    int *data;
    int totalRows;
    int totalCols;
    int index;

    data = GetMatrix(&totalRows, &totalCols);

    if (data == NULL) {
        return 0;
    }

    printf("\n--- Result ---\n");

    for (index = 0; index < totalRows * totalCols; index++) {
        printf("data[%d] = %d\n", index, data[index]);
    }

    free(data);

    return 0;
}