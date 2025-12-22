#include <stdio.h>

struct student {
    int id;
    int score;
};

/* Prototype */
void GetStudent(struct student child[][10], int *room);

int main() {
    struct student children[20][10];
    int group;

    GetStudent(children, &group);

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

    return 0;
}

void GetStudent(struct student child[][10], int *room) {
    printf("Enter number of rooms: ");
    scanf("%d", room);

    for (int i = 0; i < *room; i++) {
        printf("\n--- Room %d ---\n", i + 1);
        for (int j = 0; j < 10; j++) {
            printf("Student %d ID: ", j + 1);
            scanf("%d", &child[i][j].id);

            printf("Student %d Score: ", j + 1);
            scanf("%d", &child[i][j].score);
        }
    }
}