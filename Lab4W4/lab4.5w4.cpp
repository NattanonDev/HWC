#include <cstdio>
#include <cstring>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

void SaveNode(struct studentNode *child, char n[], int a, char s, float g);
void GoNext2(struct studentNode **walk);

int main() {
    struct studentNode *start, *now1, **now2;

    start = new struct studentNode;
    SaveNode(start, (char *)"one", 6, 'M', 3.11f);

    start->next = new struct studentNode;
    SaveNode(start->next, (char *)"two", 8, 'F', 3.22f);

    start->next->next = new struct studentNode;
    SaveNode(start->next->next, (char *)"three", 10, 'M', 3.33f);

    start->next->next->next = new struct studentNode;
    SaveNode(start->next->next->next, (char *)"four", 12, 'F', 3.44f);

    start->next->next->next->next = NULL; // โหนดสุดท้าย

    now1 = start;
    now2 = &start;

    GoNext2(now2);
    printf("%s ", (*now2)->name);

    return 0;
}

void SaveNode(struct studentNode *child, char n[], int a, char s, float g) {
    strcpy(child->name, n);
    child->age = a;
    child->sex = s;
    child->gpa = g;
    child->next = NULL;
}

void GoNext2(struct studentNode **walk) {
    if (walk != NULL && *walk != NULL && (*walk)->next != NULL) {
        *walk = (*walk)->next;   // เลื่อน start ผ่าน now2
    }
}