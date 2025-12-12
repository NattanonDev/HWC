#include <stdio.h>

void explode(char str1[], char splitter, char str2[][10], int *count);

int main() {
    char out[20][10];
    int num = 0;
    int i;

    explode("I/Love/You", '/', out, &num);

    // แสดงผลลัพธ์
    for (i = 0; i < num; i++) {
        printf("str2[%d] = \"%s\"\n", i, out[i]);
    }

    printf("count = %d\n", num);

    return 0;
}

void explode(char str1[], char splitter, char str2[][10], int *count) {
    int i = 0;
    int row = 0;
    int col = 0;

    // เริ่มต้นจำนวนคำที่แยกได้เป็น 0
    *count = 0;

    while (str1[i] != '\0') {

        // ถ้าเจอตัวแบ่ง
        if (str1[i] == splitter) {
            str2[row][col] = '\0';   // ปิด string
            row++;                   // ไปคำถัดไป
            col = 0;
            (*count)++;
        } else {
            str2[row][col] = str1[i];
            col++;
        }

        i++;
    }

    // ปิด string คำสุดท้าย
    str2[row][col] = '\0';
    (*count)++;
}