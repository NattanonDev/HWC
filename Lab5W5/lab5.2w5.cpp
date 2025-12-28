#include <cstdio>
#include <cstring>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

void ShowAll1(struct studentNode **walk);

void InsNode(struct studentNode **now, const char n[], int a, char s, float g);
void GoNext(struct studentNode ***walk);
void DelNode(struct studentNode **now);

static void SaveNode(struct studentNode *child, const char n[], int a, char s, float g);

int main() {
    struct studentNode *start, **now;

    start = NULL;
    now = &start;

    InsNode(now, "one", 6, 'M', 3.11f);     ShowAll1(&start);
    InsNode(now, "two", 8, 'F', 3.22f);     ShowAll1(&start);

    GoNext(&now);

    InsNode(now, "three", 10, 'M', 3.33f);  ShowAll1(&start);
    InsNode(now, "four", 12, 'F', 3.44f);   ShowAll1(&start);

    GoNext(&now);

    DelNode(now);                           ShowAll1(&start);

    return 0;
}

void ShowAll1(struct studentNode **walk) {
    while (*walk != NULL) {
        printf("%s ", (*walk)->name);
        walk = &((*walk)->next);
    }
    printf("\n");
}

static void SaveNode(struct studentNode *child, const char n[], int a, char s, float g) {
    strcpy(child->name, n);
    child->age = a;
    child->sex = s;
    child->gpa = g;
    child->next = NULL;
}

/* แทรกโหนดใหม่ "ก่อนโหนดปัจจุบัน" ที่ *now ชี้อยู่ */
void InsNode(struct studentNode **now, const char n[], int a, char s, float g) {
    struct studentNode *node = new struct studentNode;
    SaveNode(node, n, a, s, g);

    node->next = *now;
    *now = node;
}

/* ขยับตำแหน่ง now ให้ไปอ้างถึงลิงก์ถัดไป */
void GoNext(struct studentNode ***walk) {
    if (walk == NULL || *walk == NULL) return;
    if (**walk == NULL) return;                // ไม่มีโหนดปัจจุบัน
    *walk = &((**walk)->next);                 // now = &((*now)->next)
}

/* ลบโหนดปัจจุบันที่ *now ชี้อยู่ */
void DelNode(struct studentNode **now) {
    if (now == NULL || *now == NULL) return;

    struct studentNode *temp = *now;
    *now = temp->next;
    delete temp;
}