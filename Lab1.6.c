#include <stdio.h>

int main() {
    int number;

    do
    {
        printf("Enter a number (1-10): ");

        if(scanf("%d",&number)!=1){
            return 0;
        }

        if(!(number >= 1 && number <= 10)){
            puts("Error: Value must be 1-10.");
        }

    }while(!(number >= 1 && number <= 10));

    printf("Input accepted: %d\n", number);
    return 0;
}
