#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* =========================
   Struct
   ========================= */
struct studentNode {
    char  name[20];
    int   age;
    char  sex;
    float gpa;

    studentNode *next;   // ใช้ทำลิงค์ลิสต์
};

/* =========================
   Prototype (Class)
   ========================= */
class LinkedList {
protected:
    struct studentNode *start, **now;

public:
    LinkedList();
    ~LinkedList();

    void InsNode(char n[], int a, char s, float g);
    void DelNode();
    void GoNext();
    virtual void ShowNode();
};

class NewList : public LinkedList {
public:
    void GoFirst();
    void InsertNode(char n[], int a, char s, float g); // ให้ตรงกับ main ที่เรียก InsertNode
    virtual void ShowNode();
};

/* =========================
   Main
   ========================= */
int main() {
    LinkedList listA;
    NewList    listB;
    LinkedList *listC;

    listA.InsNode((char*)"one",   1, 'A', 1.1f);
    listA.InsNode((char*)"two",   2, 'B', 2.2f);
    listA.InsNode((char*)"three", 3, 'C', 3.3f);
    listA.GoNext();
    listA.ShowNode();

    listB.InsertNode((char*)"four", 4, 'D', 4.4f);
    listB.InsertNode((char*)"five", 5, 'E', 5.5f);
    listB.InsertNode((char*)"six",  6, 'F', 6.6f);
    listB.GoNext();
    listB.DelNode();
    listB.ShowNode();

    listC = &listA;
    listC->GoNext();
    listC->ShowNode();

    listC = &listB;
    listC->ShowNode();

    return 0;
}

/* =========================
   Function / Implementation
   ========================= */
LinkedList::LinkedList() {
    start = NULL;
    now = &start;   // now ชี้มาที่ "ช่อง pointer" ของโหนดปัจจุบัน
}

LinkedList::~LinkedList() {
    studentNode *p = start;
    while (p != NULL) {
        studentNode *tmp = p->next;
        free(p);
        p = tmp;
    }
    start = NULL;
    now = &start;
}

void LinkedList::InsNode(char n[], int a, char s, float g) {
    studentNode *p = (studentNode*)malloc(sizeof(studentNode));
    if (p == NULL) return;

    strcpy(p->name, n);
    p->age = a;
    p->sex = s;
    p->gpa = g;

    // แทรก "หน้าตำแหน่งปัจจุบัน" ที่ now ชี้อยู่
    p->next = *now;
    *now = p;

    // ให้ cursor(now) ชี้ที่โหนดที่เพิ่งแทรก (เหมือนนักศึกษาทำให้เดินต่อได้)
    // (ตอนนี้ *now คือ p แล้ว)
}

void LinkedList::DelNode() {
    if (*now == NULL) return;

    studentNode *tmp = *now;
    *now = tmp->next;   // ข้ามโหนดที่ลบ
    free(tmp);
}

void LinkedList::GoNext() {
    if (*now == NULL) return;
    now = &((*now)->next);  // เลื่อนไปช่อง next ของโหนดปัจจุบัน
}

void LinkedList::ShowNode() {
    if (*now == NULL) return;
    printf("%s %d %c %.2f\n", (*now)->name, (*now)->age, (*now)->sex, (*now)->gpa);
}

/* ----- NewList ----- */
void NewList::GoFirst() {
    now = &start;
}

void NewList::InsertNode(char n[], int a, char s, float g) {
    // ทำให้ main เรียก InsertNode ได้ แต่ใช้ของเดิมคือ InsNode
    InsNode(n, a, s, g);
}

void NewList::ShowNode() {
    // โชว์แบบใหม่: ชื่อ "ตัวแรกของลิสต์" และชื่อ "โหนดที่ now ชี้อยู่"
    if (start == NULL || *now == NULL) return;
    printf("%s %s\n", start->name, (*now)->name);
}