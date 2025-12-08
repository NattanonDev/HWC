#include <stdio.h>
#include <string.h>

void reverse(char str1[], char str2[]) {
    int len = strlen(str1);
    int j = 0;

    // ไล่จากท้ายไปหน้า
    for (int i = len - 1; i >= 0; i--) {
        str2[j++] = str1[i];
    }
    str2[j] = '\0';  // ปิดท้ายสตริง
}

int main() {
    char text[50];
    char out[50];

    fgets(text, sizeof(text), stdin);

    // ลบ newline '\n' ที่ fgets เก็บมาด้วย
    text[strcspn(text, "\n")] = '\0';

    reverse(text, out);

    printf("%s", out);
    return 0;
}
