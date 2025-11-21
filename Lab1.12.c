#include <stdio.h>

int main() {
    int planCode;
    float dataUsage_GB;
    float totalBill = 0.0;
    
    // รับค่ารหัสแพ็กเกจและปริมาณการใช้ข้อมูล
    if (scanf("%d %f", &planCode, &dataUsage_GB) != 2) {
        return 1; 
    }

    // คำนวณค่าบริการตามแผน
    switch (planCode)
    {
    case 1:  // Basic Plan
        if (dataUsage_GB <= 10) {
            totalBill = 299;
        } else {
            totalBill = 299 + 10 * (dataUsage_GB - 10);
        }
        break;

    case 2:  // Premium Plan
        if (dataUsage_GB <= 20) {
            totalBill = 599;
        } else {
            totalBill = 599 + 50 + 5 * (dataUsage_GB - 20);
        }
        break;

    default:
        break;
    }

    // โค้ดบังคับจากอาจารย์
    if (planCode == 1 || planCode == 2) {
        printf("%.2f\n", totalBill);
    } else {
        printf("Invalid Plan Code\n");
    }

    return 0;
}