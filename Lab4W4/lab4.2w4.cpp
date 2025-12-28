#include <cstdio>

void go(int ***p, int **z);

int main() {
    int *b = new int;  *b = 10;
    int *c = new int;  *c = 20;
    int **a;

    go(&a, &b);
    std::printf("%d %p %p %p\n", **a, (void *)*a, (void *)a, (void *)&a);

    go(&a, &c);
    std::printf("%d %p %p %p\n", **a, (void *)*a, (void *)a, (void *)&a);

    delete b;
    delete c;
    return 0;
}

void go(int ***p, int **z) {
    *p = z;   // เปลี่ยน a ให้ไปชี้ &b หรือ &c
}