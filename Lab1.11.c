#include <stdio.h>

int main() {
    int categoryCode;
    float price_before_vat;
    float totalBill = 0.0;
    float vatAmount = 0.0;
    
    // รับค่าราคาก่อน VAT และรหัสหมวดหมู่
    if (scanf("%f %d", &price_before_vat, &categoryCode) != 2) {
        return 1; // Handle input failure
    }
    
    switch (categoryCode) {

        case 1:
            // Standard VAT 7%
            totalBill = price_before_vat * 1.07;
            break;

        case 2:
            // Zero Rated (VAT 0%)
            totalBill = price_before_vat;
            break;

        case 3:
            // Luxury VAT 15%
            totalBill = price_before_vat * 1.15;
            break;

        default:
            // ไม่ใช่ category 1–3
            totalBill = 0.0; 
            break;
    }

    if (categoryCode >= 1 && categoryCode <= 3) {
        vatAmount = totalBill - price_before_vat;
        printf("VAT Amount: %.2f\n", vatAmount);
        printf("Total Price: %.2f\n", totalBill);
    } else {
        printf("Invalid Category\n");
        printf("Total Price: 0.00\n");
    }

    return 0;
}
