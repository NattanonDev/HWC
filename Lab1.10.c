#include <stdio.h>

int main() {
    int clearanceLevel, age, isActive;

    // รับค่าระดับ, อายุ และสถานะ
    if (scanf("%d %d %d", &clearanceLevel, &age, &isActive) != 3) {
        return 1; 
    }

    // เงื่อนไขการตรวจสอบสิทธิ์เข้าใช้งาน
    if ( (clearanceLevel == 3 && isActive == 1) ||
         (clearanceLevel == 2 && age >= 25 && isActive == 1) ) 
    {
        printf("Access Granted");
    } else {
        printf("Access Denied");
    }

    return 0;
}