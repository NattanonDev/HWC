#include <stdio.h>
#define DAYS 7

int main() {
    int daily_temp[DAYS];
    int max_temp;
    int i;

    // รับค่าอุณหภูมิ 7 วัน (ไม่แสดงข้อความรับค่า)
    for (i = 0; i < DAYS; i++) {
        scanf("%d", &daily_temp[i]);
    }

    // กำหนดค่าเริ่มต้นของอุณหภูมิสูงสุด
    max_temp = daily_temp[0];

    // หาอุณหภูมิสูงสุด
    for (i = 1; i < DAYS; i++) {
        if (daily_temp[i] > max_temp) {
            max_temp = daily_temp[i];
        }
    }

    // แสดงรายงาน
    printf("--- DAILY TEMPERATURE REPORT ---\n");
    printf("Recorded Temperatures (C): ");

    for (i = 0; i < DAYS; i++) {
        printf("%d ", daily_temp[i]);
    }

    printf("\n");
    printf("Maximum Temperature Found: %d C\n", max_temp);

    if (max_temp >= 35) {
        printf("Weather is HOT!\n");
    } else {
        printf("Weather is MODERATE.\n");
    }

    return 0;
}