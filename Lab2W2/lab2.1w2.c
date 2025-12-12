#include <stdio.h>
#include <string.h>

// ฟังก์ชัน reverse ใช้สำหรับกลับลำดับตัวอักษรจาก str1 ไปเก็บใน str2
void reverse(char str1[], char str2[]) {
    int len = strlen(str1);   // หาความยาวของสตริงต้นทาง
    int j = 0;                // ตัวแปรสำหรับตำแหน่งของ str2

    // วนลูปจากตัวอักษรตัวสุดท้ายของ str1 ไปตัวแรก
    for (int i = len - 1; i >= 0; i--) {
        str2[j] = str1[i];    // คัดลอกตัวอักษรจากท้าย str1 มาไว้ใน str2
        j++;                  // ขยับตำแหน่งของ str2
    }

    // ใส่ null character เพื่อปิดท้ายสตริง
    str2[j] = '\0';
}

int main() {
    // กำหนดสตริงต้นทาง
    char text[50] = "I Love You";
    // ตัวแปรสำหรับเก็บสตริงที่ถูกกลับด้าน
    char out[50];

    // เรียกใช้ฟังก์ชัน reverse เพื่อกลับข้อความ
    reverse(text, out);

    // แสดงผลสตริงที่ถูกกลับด้าน
    printf("%s", out);

    return 0;   // จบการทำงานของโปรแกรม
}