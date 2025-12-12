#include <stdio.h>

// ประกาศ function ตาม pre-code
void reverse( char str1[], char str2[] );

int main() {
    char text[50] = "I Love You";
    char out[50];

    reverse(text, out);

    // แสดงผลลัพธ์
    printf("%s", out);

    return 0;
}

void reverse( char str1[], char str2[] ) {
    int len = 0;
    int i;
    int j = 0;

    // หาความยาวของข้อความใน str1
    while (str1[len] != '\0') {
        len++;
    }

    // วนลูปกลับจากตัวอักษรตัวสุดท้าย
    for (i = len - 1; i >= 0; i--) {
        str2[j] = str1[i];
        j++;
    }

    // ใส่ตัวจบสตริง
    str2[j] = '\0';
}