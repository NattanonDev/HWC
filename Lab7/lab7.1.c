#include <stdio.h>

#define FILENAME "output_data.txt"

int main() {
    FILE *fptr;
    int year = 2025;

    /* เปิดไฟล์ในโหมดเขียน (w) */
    fptr = fopen(FILENAME, "w");

    /* ตรวจสอบว่าเปิดไฟล์สำเร็จหรือไม่ */
    if (fptr == NULL) {
        printf("ERROR: Could not open file %s for writing.\n", FILENAME);
        return 1;
    }

    printf("--- FILE WRITING PROCESS ---\n");
    printf("Writing data to %s...\n", FILENAME);

    /* เขียนข้อความลงไฟล์ */
    fprintf(fptr, "Hello, C File Handling is easy.\n");
    fprintf(fptr, "%d\n", year);

    /* ปิดไฟล์ */
    fclose(fptr);

    /* แสดงรายงานบนหน้าจอ */
    printf("File writing complete.\n");
    printf("--- FILE OPERATION REPORT ---\n");
    printf("Action: File created and data written successfully.\n");
    printf("Filename: %s\n", FILENAME);

    return 0;
}