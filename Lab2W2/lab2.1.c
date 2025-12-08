#include <stdio.h>
#include <string.h>

void reverse( char str1[], char str2[] ) {
    int n = strlen(str1);
    int j = 0;

    for(int i = n-1 ; i >= 0 ; i--){
        str2[j] = str1[i];
        j++;
    }
    str2[j] = '\0';
}

int main() {
    char text[50];
    char out[50];

    gets(text);

    reverse(text, out);

    printf("%s", out);

    return 0;
}