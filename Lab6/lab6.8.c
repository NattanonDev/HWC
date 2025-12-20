#include <stdio.h>

#define SIZE 5

int find_and_update(int *arr_ptr, int size, int search_value, int new_value);
void print_array(int array[], int size);

int main() {
    int numbers[SIZE];
    int search_val;
    int new_val;
    int status;
    int i;

    printf("Enter %d integer elements for the array:\n", SIZE);
    for (i = 0; i < SIZE; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    printf("\nEnter value to search (Search Value): ");
    scanf("%d", &search_val);

    printf("Enter new value to replace it with (New Value): ");
    scanf("%d", &new_val);

    printf("\n--- ARRAY UPDATE REPORT ---\n");
    printf("Array BEFORE Update: ");
    print_array(numbers, SIZE);

    // เรียกใช้ Function เพื่อค้นหาและอัปเดตค่า
    status = find_and_update(numbers, SIZE, search_val, new_val);

    printf("Array AFTER Update: ");
    print_array(numbers, SIZE);

    printf("Status: ");
    if (status == 1) {
        printf("Success\n");
    } else {
        printf("Failed\n");
    }

    return 0;
}

/* ฟังก์ชันค้นหาและอัปเดตค่าใน Array */
int find_and_update(int *arr_ptr, int size, int search_value, int new_value) {
    int i;

    for (i = 0; i < size; i++) {
        if (*(arr_ptr + i) == search_value) {
            *(arr_ptr + i) = new_value;   // อัปเดตค่าผ่าน Pointer
            return 1;                     // พบและอัปเดตสำเร็จ
        }
    }
    return 0;   // ไม่พบค่า
}

/* ฟังก์ชันแสดงค่าใน Array */
void print_array(int array[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}