#include <stdio.h>

int main() {
    int number;

    do {
        printf("Enter a number (1-10): ");

        // รับค่าจากผู้ใช้ ถ้าอ่านไม่ได้ เช่นพิมพ์ตัวอักษร ให้หยุดโปรแกรม
        if (scanf("%d", &number) != 1) {
            break;
        }

        // ถ้าค่าที่กรอกมานอกช่วงน้อยกว่า 1 หรือ มากกว่า 10 จะแสดงข้อความ Error: Value must be 1-10.
        if (number < 1 || number > 10) {
            printf("Error: Value must be 1-10.\n");
        }

    } while (number < 1 || number > 10);  // เงื่อนไขลูป ถ้าค่าผิด ต้องวนซ้ำอีก

    // เมื่อค่าถูกต้อง (1–10) จะแสดงข้อความนี้
    printf("Input accepted: %d\n", number);

    return 0;
}
