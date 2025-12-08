#include <stdio.h>
#include <string.h>

void reverse( char str1[], char str2[] ) {
    int n = strlen(str1);
    int j = 0;

    for(int i = n - 1; i >= 0; i--){
        str2[j++] = str1[i];
    }

    str2[j] = '\0';
}

int main() {
    char text[50];
    char out[50];

    fgets(text, 50, stdin);

    // ลบ newline ของ fgets ถ้ามี
    text[strcspn(text, "\n")] = '\0';

    reverse(text, out);

    printf("%s", out);

    return 0;
}