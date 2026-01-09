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
    studentNode *back;
};

/***************************
 *        Prototype
 ***************************/
void ShowAll(struct studentNode *walk);

studentNode* AddNode(struct studentNode **start,
                     const char n[], int a, char s, float g);

void InsNode(struct studentNode *now,
             const char n[], int a, char s, float g);

void GoBack(struct studentNode **now);

/* ลบโหนดปัจจุบัน แล้วให้ now ขยับไปโหนดถัดไป */
void DelNode(struct studentNode **now, struct studentNode **start);

static void SaveNode(struct studentNode *child,
                     const char n[], int a, char s, float g);

/***************************
 *           Main
 ***************************/
int main() {
    struct studentNode *start, *now;
    start = NULL;

    now = AddNode(&start, "one", 6, 'M', 3.11f);   ShowAll(start);
    now = AddNode(&start, "two", 8, 'F', 3.22f);   ShowAll(start);

    InsNode(now, "three", 10, 'M', 3.33f);         ShowAll(start);
    InsNode(now, "four", 12, 'F', 3.44f);          ShowAll(start);

    GoBack(&now);

    DelNode(&now, &start);                         ShowAll(start);
    DelNode(&now, &start);                         ShowAll(start);
    DelNode(&now, &start);                         ShowAll(start);

    return 0;
}

/***************************
 *         Function
 ***************************/
void ShowAll(struct studentNode *walk) {
    while (walk != NULL) {
        printf("%s ", walk->name);
        walk = walk->next;
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
    child->back = NULL;
}

/* เพิ่มท้ายลิสต์ + เซ็ต back ให้ถูก + คืนโหนดใหม่ */
studentNode* AddNode(struct studentNode **start,
                     const char n[], int a, char s, float g) {
    studentNode *node = new studentNode;
    SaveNode(node, n, a, s, g);

    if (*start == NULL) {
        *start = node;
        return node;
    }

    studentNode *walk = *start;
    while (walk->next != NULL) {
        walk = walk->next;
    }

    walk->next = node;
    node->back = walk;
    return node;
}

/* แทรกโหนดใหม่ "ต่อจาก now" (ต้องจัด next/back ทั้งสองฝั่ง) */
void InsNode(struct studentNode *now,
             const char n[], int a, char s, float g) {
    if (now == NULL) return;

    studentNode *node = new studentNode;
    SaveNode(node, n, a, s, g);

    studentNode *temp = now->next;

    node->next = temp;
    node->back = now;

    now->next = node;
    if (temp != NULL) {
        temp->back = node;
    }
}

/* ถอย now ไปโหนดก่อนหน้า */
void GoBack(struct studentNode **now) {
    if (now == NULL) return;
    if (*now == NULL) return;
    if ((*now)->back == NULL) return;

    *now = (*now)->back;
}

/* ลบโหนดปัจจุบัน แล้วเลื่อน now ไปโหนดถัดไป */
void DelNode(struct studentNode **now, struct studentNode **start) {
    if (now == NULL || *now == NULL) return;

    studentNode *cur = *now;
    studentNode *prev = cur->back;
    studentNode *next = cur->next;

    /* ตัด cur ออกจากลิสต์ */
    if (prev != NULL) prev->next = next;
    if (next != NULL) next->back = prev;

    /* ถ้าลบหัวลิสต์ ต้องอัปเดต start */
    if (start != NULL && *start == cur) {
        *start = next;
    }

    /* now ต้องชี้ไปตัวถัดไปตามโจทย์ */
    *now = next;

    delete cur;
}