#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

void SaveNode(struct studentNode *child, char n[], int a, char s, float g);
void GoNext1(struct studentNode *walk);

int main(void) {
    struct studentNode *start, *now1;
    struct studentNode **now2; 

    start = (struct studentNode *)malloc(sizeof(struct studentNode));
    SaveNode(start, "one", 6, 'M', 3.11);

    start->next = (struct studentNode *)malloc(sizeof(struct studentNode));
    SaveNode(start->next, "two", 8, 'F', 3.22);

    start->next->next = (struct studentNode *)malloc(sizeof(struct studentNode));
    SaveNode(start->next->next, "three", 10, 'M', 3.33);

    start->next->next->next = (struct studentNode *)malloc(sizeof(struct studentNode));
    SaveNode(start->next->next->next, "four", 12, 'F', 3.44);

    /* ปิดท้าย list */
    start->next->next->next->next = NULL;

    now1 = start;
    now2 = &start;

    GoNext1(now1);
    printf("now1 still points to: %s\n", now1->name);

    return 0;
}

void SaveNode(struct studentNode *child, char n[], int a, char s, float g) {
    strcpy(child->name, n);
    child->age = a;
    child->sex = s;
    child->gpa = g;
    child->next = NULL; /* กันหลุดถ้ายังไม่ได้ต่อ */
}

void GoNext1(struct studentNode *walk) {
    if (walk == NULL) {
        printf("walk is NULL\n");
        return;
    }

    if (walk->next == NULL) {
        printf("No next node\n");
        return;
    }

    walk = walk->next; /* เปลี่ยนได้แค่ walk ในฟังก์ชัน */
    printf("Inside GoNext1 -> moved to: %s\n", walk->name);
}