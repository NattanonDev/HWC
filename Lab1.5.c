#include <stdio.h>   // ไลบรารีสำหรับ printf และ scanf

int main() {
    int number;
    int evenSum = 0;   // ใช้เก็บผลรวมของเลขคู่
    int oddSum = 0;    // ใช้เก็บผลรวมของเลขคี่

    // รับตัวเลขตัวแรกก่อนเริ่มลูป
    // ถ้ารับค่าไม่ได้ ให้จบโปรแกรม
    if (scanf("%d", &number) != 1) {
        return 1;
    }

    /*
        ลูปนี้จะทำงานไปเรื่อย ๆ ตราบใดที่ number ไม่ใช่ 0
        ถ้าเป็นเลขคู่ (หาร 2 ลงตัว) → สะสมใน evenSum
        ถ้าเป็นเลขคี่ → สะสมใน oddSum
    */
    while (number != 0) {

        // เช็คเลขคู่หรือเลขคี่
        if (number % 2 == 0) {
            evenSum += number;   // สะสมเลขคู่
        } else {
            oddSum += number;    // สะสมเลขคี่
        }

        // รับค่าตัวเลขถัดไปที่ท้ายลูป
        if (scanf("%d", &number) != 1) {
            break;   // ถ้ารับค่าไม่ได้ ให้ออกจากลูป
        }
    }

    // แสดงผลรวมของเลขคู่และเลขคี่
    printf("Even Sum: %d\n", evenSum);
    printf("Odd Sum: %d\n", oddSum);

    return 0;   // จบโปรแกรม
}