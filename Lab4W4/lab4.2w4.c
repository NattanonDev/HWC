#include <stdio.h>
#include <stdlib.h>

void go(int ***p, int **z);

int main(void) {
    int *b = (int *)malloc(sizeof(int));
    int *c = (int *)malloc(sizeof(int));
    int **a;              /* pointer 2 ระดับ */

    *b = 10;
    *c = 20;

    go(&a, &b);           /* เปลี่ยนให้ a ชี้ &b */
    printf("%d %p %p %p\n",
           **a, (void *)*a, (void *)a, (void *)&a);

    go(&a, &c);           /* เปลี่ยนให้ a ชี้ &c */
    printf("%d %p %p %p\n",
           **a, (void *)*a, (void *)a, (void *)&a);

    free(b);
    free(c);
    return 0;
}

void go(int ***p, int **z) {
    *p = z;               /* แก้ค่า a ใน main */
}