#include <stdio.h>
#include <string.h>

void reverse(char str1[], char str2[]) {
    int len = strlen(str1);
    int j = 0;

    for (int i = len - 1; i >= 0; i--) {
        str2[j] = str1[i];
        j++;
    }
    str2[j] = '\0';
}

int main() {
    char text[50] = "I Love You";
    char out[50];

    reverse(text, out);

    printf("%s", out);
    return 0;
}
