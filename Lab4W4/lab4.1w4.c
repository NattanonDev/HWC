#include <stdio.h>

void go(int **p,int *z);

int main(void) {
    int *a; /* pointer 1 ระดับ */
    int b = 10, c = 20;

    go(&a,&b);
    printf("%d %p %p\n", *a, a, &a);

    go(&a,&c);
    printf("%d %p %p\n", *a, a, &a);
    return 0;
}

void go (int **p,int *z){
    *p = z;
}

