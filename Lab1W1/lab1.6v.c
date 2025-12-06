#include <stdio.h>
#include <stdlib.h>

int *GetMatrix(int *row, int *col);

int main()
{
    int *data;
    int m;
    int n;
    int i;
    int j;

    data = GetMatrix(&m, &n);

    printf("\nMatrix Input\n");

    for (i = 0; i < m; i++) {
        printf("%d row\n", i + 1);

        for (j = 0; j < n; j++) {
            printf("%d col number: ", j + 1);
            scanf("%d", &data[i * n + j]);
        }
    }

    return 0;
}

int *GetMatrix(int *row, int *col)
{
    int *Pvar;
    int total;

    printf("How many row, col ? : ");
    scanf("%d %d", row, col);

    /* สร้างพื้นที่เก็บข้อมูลตามจำนวนที่ผู้ใช้ใส่ */
    total = (*row) * (*col);

    Pvar = (int *)malloc(total * sizeof(int));

    return Pvar;
}
