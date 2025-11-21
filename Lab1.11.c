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

    // คำนวณราคาตามหมวดหมู่สินค้า
    if (categoryCode == 1) {
        totalBill = price_before_vat * 1.07;   // VAT 7%
    }
    else if (categoryCode == 2) {
        totalBill = price_before_vat;          // VAT 0%
    }
    else if (categoryCode == 3) {
        totalBill = price_before_vat * 1.15;   // VAT 15%
    }
    else {
        totalBill = 0.0;
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