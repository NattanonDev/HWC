#include <stdio.h>

int main() {
    int customerType;
    float consumption_kWh;
    float totalBill = 0.0;

    // รับข้อมูล 2 ค่า รหัสประเภทลูกค้า (customerType) และ ปริมาณการใช้ไฟฟ้า (consumption_kWh)
    if (scanf("%d %f", &customerType, &consumption_kWh) != 2) {
        return 1;
    }

    // ตรวจสอบประเภทลูกค้า
    if (customerType == 1) {
        // Customer Type 1: ครัวเรือน
        if (consumption_kWh <= 100) {
            totalBill = consumption_kWh * 3.0;
        } else {
            totalBill = consumption_kWh * 4.0;
        }
    }
    else if (customerType == 2) {
        // Customer Type 2: ธุรกิจ
        if (consumption_kWh <= 500) {
            totalBill = consumption_kWh * 5.0;
        } else {
            totalBill = consumption_kWh * 6.5;
        }
    }
    else {
        // ถ้าประเภทไม่ใช่ 1 หรือ 2 = Invalid
        printf("Invalid Customer Type\n");
        customerType = 3;
    }

    if (totalBill > 0.0 || customerType == 3) {
        printf("%.2f\n", totalBill);
    }

    return 0;
}
