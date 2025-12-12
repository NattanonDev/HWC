#include <stdio.h>

char* reverse(char str1[]);

int main() {
    char text[50] = "I Love You";
    char *out;

    out = reverse(text);
    printf("%s", out);

    return 0;
}

char* reverse(char str1[]) {
    static char result[50];
    int start = 0;
    int end = 0;

    // หาตำแหน่งตัวสุดท้ายของ string
    while (str1[end] != '\0') {
        end++;
    }
    end--;   // ถอยกลับมาที่ตัวอักษรสุดท้าย

    // กลับข้อความโดยใช้หัว-ท้าย
    while (end >= 0) {
        result[start] = str1[end];
        start++;
        end--;
    }

    result[start] = '\0';

    return result;
}
