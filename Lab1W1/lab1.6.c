#include <stdio.h>
#include <stdlib.h>

/* ฟังก์ชันนี้รับจำนวนแถวและคอลัมน์ และสร้างพื้นที่เก็บข้อมูลแบบ dynamic
   WHY: ต้อง return pointer เพราะ main ต้องนำข้อมูลไปใช้งานต่อ */
int *GetMatrix(int *row, int *col)
{
    int r;
    int c;
    int i;
    int total;
    int *value;

    printf("Enter number of rows: ");
    if (scanf("%d", &r) != 1) {
        printf("Invalid input.\n");
        return NULL;
    }

    printf("Enter number of columns: ");
    if (scanf("%d", &c) != 1) {
        printf("Invalid input.\n");
        return NULL;
    }

    total = r * c;

    /* WHY: ใช้ malloc เพราะจำนวนข้อมูลขึ้นอยู่กับผู้ใช้ ไม่สามารถกำหนดล่วงหน้าได้ */
    value = malloc(total * sizeof(int));
    if (value == NULL) {
        printf("Allocation failed.\n");
        return NULL;
    }

    for (i = 0; i < total; i++) {

        printf("Enter value %d: ", i + 1);

        if (scanf("%d", &value[i]) != 1) {
            printf("Invalid input.\n");
            free(value);
            return NULL;
        }
    }

    *row = r;
    *col = c;

    return value;
}

int main()
{
    int *data;
    int m;
    int n;
    int index;

    data = GetMatrix(&m, &n);

    printf("\n--- Result ---\n");
    for (index = 0; index < m * n; index++) {
        printf("data[%d] = %d\n", index, data[index]);
    }

    free(data);

    return 0;
}