#include <stdio.h>

int main(){
    int n;
    int even=0, odd = 0;

    if(scanf("%d",&n)!=1){
        return 1;
    }

    while(n!=0){

        if(n%2==0){
            even = even + n;
        }else{
            odd = odd + n;
        }

        scanf("%d",&n);
    }

    printf("Even Sum: %d\n",even);
    printf("Odd Sum: %d\n",odd);
    return 0;
}
