#include <stdio.h>

int main() {
    int dayCode, hour;
    
    // รับค่ารหัสวันและชั่วโมง
    if (scanf("%d %d", &dayCode, &hour) != 2) {
        return 1;
    }
    
    switch (dayCode)
    {
    // วันจันทร์ถึงศุกร์ (1-5)
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    // ตรวจสอบชั่วโมงด้วย if-else
            if (hour >= 8 && hour <= 17) {
                printf("System Running (Workday)");
            } else {
                printf("System Idle (Off-hours)");
            }
            break;
    // วันเสาร์ - อาทิตย์ (6-7)
        case 6:
        case 7:
            printf("Weekend Relax Mode");
            break;
    // ถ้า dayCode ไม่ใช่ 1-7
        default:
            printf("Invalid Day Code");
            break;
    }

    return 0;
}