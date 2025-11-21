#include <stdio.h>

int main() {
    int zoneCode;
    float weight_kg;
    float totalCost = 0.0;

    // รับค่ารหัสโซนและน้ำหนัก
    if (scanf("%d %f", &zoneCode, &weight_kg) != 2) {
        return 1;
    }

    switch (zoneCode)
    {
    case 1:
        // Zone 1: Local
        if (weight_kg <= 5) {
            totalCost = 50;
        } else {
            totalCost = 80;
        }
        break;

    case 2:
        // Zone 2: Regional
        if (weight_kg <= 10) {
            totalCost = 150;
        } else {
            totalCost = 250;
        }
        break;

    case 3:
        // Zone 3: International
        totalCost = 500;
        break;

    default:
        // Zone Code ไม่ใช่ 1, 2, หรือ 3
        printf("Invalid Zone Code\n");
        break;
    }


    if (totalCost > 0.0 || zoneCode > 3 || zoneCode < 1) {
        printf("%.2f\n", totalCost);
    }

    return 0;
}
