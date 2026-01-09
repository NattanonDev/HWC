/***************************
 *        Include
 ***************************/
#include <cstdio>
#include <cstring>

/***************************
 *         Struct
 ***************************/
struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    studentNode *next;
};

/***************************
 *        Prototype
 ***************************/
void ShowAll1(struct studentNode **walk);

void InsNode(struct studentNode **now,
             const char n[], int a, char s, float g);

void GoNext(struct studentNode ***walk);

void DelNode(struct studentNode **now);

static void SaveNode(struct studentNode *child,
                     const char n[], int a, char s, float g);

/***************************
 *           Main
 ***************************/
int main() {
    struct studentNode *start, **now;

    start = NULL;
    now = &start;

    InsNode(now, "one", 6, 'M', 3.11f);   ShowAll1(&start);
    InsNode(now, "two", 8, 'F', 3.22f);   ShowAll1(&start);

    GoNext(&now);

    InsNode(now, "three", 10, 'M', 3.33f);  ShowAll1(&start);
    InsNode(now, "four", 12, 'F', 3.44f);   ShowAll1(&start);

    GoNext(&now);

    DelNode(now);  ShowAll1(&start);

    return 0;
}

/***************************
 *         Function
 ***************************/
void ShowAll1(struct studentNode **walk) {
    while (*walk != NULL) {
        printf("%s ", (*walk)->name);
        walk = &((*walk)->next);   // เดินแบบ “ชี้ช่อง next”
    }
    printf("\n");
}

static void SaveNode(struct studentNode *child,
                     const char n[], int a, char s, float g) {
    strcpy(child->name, n);
    child->age = a;
    child->sex = s;
    child->gpa = g;
    child->next = NULL;
}

/* แทรกโหนดใหม่ "ก่อน" โหนดที่ *now ชี้อยู่ */
void InsNode(struct studentNode **now,
             const char n[], int a, char s, float g) {
    studentNode *node = new studentNode;
    SaveNode(node, n, a, s, g);

    node->next = *now;  // ต่อโหนดใหม่เข้ากับของเดิม
    *now = node;        // เปลี่ยนช่องพอยน์เตอร์ให้ชี้โหนดใหม่
}

/* ขยับตำแหน่ง now ให้ไปชี้ “ช่อง next” ของโหนดปัจจุบัน */
void GoNext(struct studentNode ***walk) {
    if (walk == NULL) return;
    if (*walk == NULL) return;
    if (**walk == NULL) return;          // ยังไม่มีโหนดให้ขยับ

    *walk = &((**walk)->next);           // now = &((*now)->next)
}

/* ลบโหนดปัจจุบัน (ที่ *now ชี้อยู่) */
void DelNode(struct studentNode **now) {
    if (now == NULL) return;
    if (*now == NULL) return;

    studentNode *temp = *now;
    *now = temp->next;   // ข้ามตัวที่จะลบ
    delete temp;
}