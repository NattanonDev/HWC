#include <stdio.h>

int main() {

    int N;      // ตัวแปรเก็บจำนวนข้อมูลที่ต้องการอ่าน
    int i;      // ตัวแปรใช้วนลูป

    printf("number : ");
    if (scanf("%d", &N) != 1) {   // รับจำนวน N และตรวจสอบว่ารับค่าได้จริงหรือไม่
        return 1;                 // ถ้ารับไม่ได้ให้จบโปรแกรม
    }

    int scores[N];   // สร้าง Array ขนาด N เพื่อเก็บค่าที่ผู้ใช้กรอก

    // ลูปเพื่อรับค่าตัวเลขทีละตัว แล้วเก็บลงใน Array
    for (i = 0; i < N; i++) {
        printf("value : ");
        if (scanf("%d", &scores[i]) != 1) {  // ตรวจสอบการรับค่าครั้งละตัว
            return 1;
        }
    }

    printf("\n");

    // ลูปแสดงผลจากท้าย Array ไปหน้า (ย้อนกลับ)
    for (i = N - 1; i >= 0; i--) {
        printf("output : ");
        printf("%d\n", scores[i]);
    }

    return 0;   // จบโปรแกรมปกติ
}