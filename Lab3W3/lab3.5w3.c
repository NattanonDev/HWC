#include <stdio.h>
#include <stdlib.h>

struct student {
    int id;
    int score;
};

/* Prototype */
struct student (*GetStudent(int *room))[10];

int main() {
    struct student (*children)[10];
    int group;
    children = GetStudent(&group);

    /* แสดงผล */
    printf("\n--- STUDENT REPORT ---\n");
    printf("Total Rooms: %d\n", group);

    for (int i = 0; i < group; i++) {
        printf("\nRoom %d\n", i + 1);
        for (int j = 0; j < 10; j++) {
            printf("Student %d -> ID: %d, Score: %d\n",
                   j + 1,
                   children[i][j].id,
                   children[i][j].score);
        }
    }

    /* คืนหน่วยความจำ */
    free(children);

    return 0;
}

struct student (*GetStudent(int *room))[10] {
    printf("Enter number of rooms: ");
    scanf("%d", room);

    /* จองหน่วยความจำสำหรับ room ห้อง ห้องละ 10 คน */
    struct student (*child)[10] = malloc((*room) * sizeof *child);
    if (child == NULL) {
        printf("ERROR: Memory allocation failed!\n");
        exit(1);
    }

    for (int i = 0; i < *room; i++) {
        printf("\n--- Room %d ---\n", i + 1);
        for (int j = 0; j < 10; j++) {
            printf("Student %d ID: ", j + 1);
            scanf("%d", &child[i][j].id);

            printf("Student %d Score: ", j + 1);
            scanf("%d", &child[i][j].score);
        }
    }

    return child; /* คืน pointer กลับไปให้ main */
}