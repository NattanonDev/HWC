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
void GoNext1(struct studentNode **walk);

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

    start->next->next->next->next = NULL;  // โหนดสุดท้าย

    now1 = start;
    now2 = &start;   // pointer 2 ระดับ (ยังไม่ใช้ในฟังก์ชันนี้)

    GoNext1(&now1);  // ขยับ now1 ไปโหนดถัดไป
    printf("%s ", now1->name);

    return 0;
}

void SaveNode(struct studentNode *child, char n[], int a, char s, float g) {
    strcpy(child->name, n);
    child->age = a;
    child->sex = s;
    child->gpa = g;
    child->next = NULL;
}

void GoNext1(struct studentNode **walk) {
    if (*walk != NULL && (*walk)->next != NULL) {
        *walk = (*walk)->next;   // เปลี่ยน now1 ใน main
    }
}