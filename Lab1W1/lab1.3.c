#include <stdio.h>
#include <stdlib.h>

int *GetSet(int *num);

int main()
{
    int *data;
    int num;
    int i;

    /* เรียกให้ผู้ใช้กำหนดจำนวนข้อมูล และอ่านค่าต่าง ๆ เข้าเก็บ */
    data = GetSet(&num);

    /* แสดงผลข้อมูลที่ถูกบันทึก */
    printf("\n--- Result ---\n");
    for (i = 0; i < num; i++) {
        printf("data[%d] = %d\n", i, data[i]);
    }

    /* คืนหน่วยความจำที่จองไว้ */
    free(data);
    return 0;
}

int *GetSet(int *num)
{
    int i;
    int *data;

    /* รับจำนวนสมาชิกที่ต้องการเก็บ */
    printf("Enter number of elements: ");
    if (scanf("%d", num) != 1) {
        printf("No number!\n");
        return NULL;
    }

    /* จองพื้นที่ตามจำนวนสมาชิก */
    data = (int *)malloc((*num) * sizeof(int));
    if (data == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    /* รับค่าตัวเลขแต่ละตัว */
    for (i = 0; i < *num; i++) {
        printf("Enter Number %d: ", i + 1);
        if (scanf("%d", &data[i]) != 1) {
            printf("No number!\n");
            free(data);
            return NULL;
        }
    }

    return data;
}