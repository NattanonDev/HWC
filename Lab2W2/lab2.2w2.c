#include <stdio.h>

// ประกาศ function ตาม pre-code
char* reverse( char str1[] );

int main() {
    char text[50] = "I Love You";
    char *out;

    out = reverse(text);

    // แสดงผลลัพธ์
    printf("%s", out);

    return 0;
}

char* reverse( char str1[] ) {
    static char str2[50];   // ใช้ static เพื่อให้ค่าคงอยู่หลังออกจาก function
    int len = 0;
    int i;
    int j = 0;

    // หาความยาวของ string
    while (str1[len] != '\0') {
        len++;
    }

    // กลับตัวอักษรจากหลังไปหน้า
    for (i = len - 1; i >= 0; i--) {
        str2[j] = str1[i];
        j++;
    }

    // ใส่ตัวจบ string
    str2[j] = '\0';

    // ส่ง address ของ string ที่กลับแล้วกลับไป (ใน main จะนำไปเก็บใน out)
    return str2;
}
