#include <stdio.h>

int main() {
    int zoneCode;
    float weight_kg;
    float totalCost = 0.0;

    if (scanf("%d %f", &zoneCode, &weight_kg) != 2) {
        return 1;
    }

    switch (zoneCode) {
        case 1:
            if (weight_kg <= 5) {
                totalCost = 50;
            } else {
                totalCost = 80;
            }
            break;

        case 2:
            if (weight_kg <= 10) {
                totalCost = 150;
            } else {
                totalCost = 250;
            }
            break;

        case 3:
            totalCost = 500;
            break;

        default:
            printf("Invalid Zone Code");
            zoneCode = 0;
    }

    if (zoneCode > 0) {
        printf("%.2f", totalCost);
    }

    return 0;
}
