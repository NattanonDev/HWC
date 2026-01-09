/***************************
 *        Include
 ***************************/
#include <cstdio>
#include <cstring>

/*
  ใช้ printf สำหรับแสดงผล
  ใช้ strcpy สำหรับคัดลอกชื่อ
*/


/***************************
 *         Struct
 ***************************/
struct studentNode {
    char name[20];     // ชื่อ
    int age;           // อายุ
    char sex;          // เพศ
    float gpa;         // เกรดเฉลี่ย
    studentNode *next; // ชี้ไปโหนดถัดไป
};

/*
  โครงสร้างของ singly linked list
  next ใช้เชื่อมโหนดเข้าด้วยกัน
*/


/***************************
 *        Prototype
 ***************************/
void ShowAll(struct studentNode *walk);

studentNode* AddNode(struct studentNode **start,
                     const char n[], int a, char s, float g);

void InsNode(struct studentNode *now,
             const char n[], int a, char s, float g);

void DelNode(struct studentNode *now);

static void SaveNode(struct studentNode *child,
                     const char n[], int a, char s, float g);

/*
  Prototype แยกไว้ด้านบน
  เพื่อให้ main เรียกใช้ฟังก์ชันได้
*/


/***************************
 *           Main
 ***************************/
int main() {
    studentNode *start, *now;

    start = NULL;   // ลิสต์เริ่มต้นว่าง

    // เพิ่มโหนดต่อท้าย
    now = AddNode(&start, "one", 6, 'M', 3.11f);
    ShowAll(start);

    now = AddNode(&start, "two", 8, 'F', 3.22f);
    ShowAll(start);

    // แทรกโหนดต่อจากตำแหน่ง now
    InsNode(now, "three", 10, 'M', 3.33f);
    ShowAll(start);

    InsNode(now, "four", 12, 'F', 3.44f);
    ShowAll(start);

    // ลบโหนดที่อยู่ถัดจาก now
    DelNode(now);
    ShowAll(start);

    return 0;
}

/*
  main ทำหน้าที่ควบคุมลำดับการทำงาน
  start เก็บจุดเริ่มต้นของลิสต์
  now เก็บตำแหน่งปัจจุบัน
*/


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

/*
  แสดงข้อมูลทุกโหนด
  ใช้ walk เดินไปทีละโหนดจนสุดลิสต์
*/


static void SaveNode(struct studentNode *child,
                     const char n[], int a, char s, float g) {
    strcpy(child->name, n);
    child->age = a;
    child->sex = s;
    child->gpa = g;
    child->next = NULL;
}

/*
  ฟังก์ชันช่วยใส่ข้อมูลให้โหนด
  แยกไว้เพื่อไม่ให้โค้ดซ้ำ
*/


studentNode* AddNode(struct studentNode **start,
                     const char n[], int a, char s, float g) {
    studentNode *node = new studentNode;
    SaveNode(node, n, a, s, g);

    // ใช้ pointer เดินไปจนเจอท้ายลิสต์
    studentNode **walk = start;
    while (*walk != NULL) {
        walk = &((*walk)->next);
    }

    *walk = node;   // ต่อโหนดใหม่ท้ายลิสต์
    return node;    // คืนโหนดใหม่ให้ now
}

/*
  AddNode เพิ่มโหนดใหม่ที่ท้ายลิสต์
  ต้องใช้ pointer 2 ระดับเพื่อแก้ start ได้
*/


void InsNode(struct studentNode *now,
             const char n[], int a, char s, float g) {
    if (now == NULL) return;

    studentNode *node = new studentNode;
    SaveNode(node, n, a, s, g);

    // แทรกโหนดใหม่หลัง now
    node->next = now->next;
    now->next = node;
}

/*
  InsNode ใช้แทรกโหนดต่อจากตำแหน่งปัจจุบัน
  ต้องเก็บ next เดิมไว้ก่อน ไม่งั้นลิสต์ขาด
*/


void DelNode(struct studentNode *now) {
    if (now == NULL) return;
    if (now->next == NULL) return;

    studentNode *temp = now->next;
    now->next = temp->next;
    delete temp;
}

/*
  DelNode ลบโหนดที่อยู่ถัดจาก now
  ปรับลิงก์ก่อน แล้วค่อยคืนหน่วยความจำ
*/