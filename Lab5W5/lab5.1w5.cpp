#include <cstdio>
#include <cstring>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    studentNode *next;
};

void ShowAll1(studentNode *walk);

studentNode* AddNode(studentNode **start, const char n[], int a, char s, float g);
void InsNode(studentNode *now, const char n[], int a, char s, float g);
void DelNode(studentNode *now);

static void SaveNode(studentNode *child, const char n[], int a, char s, float g);

int main() {
    studentNode *start, *now;
    start = NULL;

    now = AddNode(&start, "one", 6, 'M', 3.11f);   ShowAll1(start);
    now = AddNode(&start, "two", 8, 'F', 3.22f);   ShowAll1(start);

    InsNode(now, "three", 10, 'M', 3.33f);         ShowAll1(start);
    InsNode(now, "four", 12, 'F', 3.44f);          ShowAll1(start);

    DelNode(now);                                   ShowAll1(start);

    return 0;
}

void ShowAll1(studentNode *walk) {
    while (walk != NULL) {
        std::printf("%s ", walk->name);
        walk = walk->next;
    }
    std::printf("\n");
}

static void SaveNode(studentNode *child, const char n[], int a, char s, float g) {
    std::strcpy(child->name, n);
    child->age = a;
    child->sex = s;
    child->gpa = g;
    child->next = NULL;
}

/* เพิ่มโหนดท้ายลิสต์ และคืน pointer โหนดใหม่ */
studentNode* AddNode(studentNode **start, const char n[], int a, char s, float g) {
    studentNode *node = new studentNode;
    SaveNode(node, n, a, s, g);

    if (*start == NULL) {      // ลิสต์ว่าง
        *start = node;
        return node;
    }

    studentNode *walk = *start;
    while (walk->next != NULL) {
        walk = walk->next;
    }
    walk->next = node;
    return node;
}

/* แทรกโหนดใหม่ต่อจาก now */
void InsNode(studentNode *now, const char n[], int a, char s, float g) {
    if (now == NULL) return;

    studentNode *node = new studentNode;
    SaveNode(node, n, a, s, g);

    studentNode *temp = now->next;
    now->next = node;
    node->next = temp;
}

/* ลบโหนดที่อยู่ "ถัดจาก now" */
void DelNode(studentNode *now) {
    if (now == NULL) return;
    if (now->next == NULL) return;

    studentNode *temp = now->next;
    now->next = temp->next;
    delete temp;
}