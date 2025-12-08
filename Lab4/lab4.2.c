#include <stdio.h>

int main() {

    int N,i;              // จำนวนข้อมูลที่ผู้ใช้ต้องการกรอก และ ตัวแปรใช้วนลูป
    int passSum = 0;    // ใช้เก็บผลรวมของคะแนนที่ผ่านเกณฑ์ (>= 50)
    int failCount = 0;  // ใช้นับจำนวนคนที่ไม่ผ่าน (< 50)

    printf("number : ");
    if (scanf("%d", &N) != 1) {   // ตรวจสอบการรับค่าจำนวน N
        return 1;                 // ถ้ารับค่าไม่ได้ให้หยุดโปรแกรม
    }

    int scores[N];      // สร้างอาเรย์สำหรับเก็บคะแนนทั้งหมด

    // ลูปสำหรับรับค่าคะแนนทีละตัว
    for (i = 0; i < N; i++) {
        printf("value : ");
        if (scanf("%d", &scores[i]) != 1) {  // รับคะแนนแต่ละตัว
            return 1;
        }

        // เช็คว่าคะแนนผ่านหรือไม่
        if (scores[i] >= 50) {
            passSum += scores[i];   // ถ้าผ่านให้บวกคะแนนเข้าไปในผลรวม
        } else {
            failCount++;            // ถ้าไม่ผ่านให้นับจำนวนคนที่ตกเพิ่ม
        }
    }

    // แสดงผลคะแนนรวมของคนที่ผ่าน และจำนวนคนที่ไม่ผ่าน
    printf("Passing Scores Sum: %d\n", passSum);
    printf("Failing Students Count: %d\n", failCount);

    return 0;   // จบโปรแกรมปกติ
}