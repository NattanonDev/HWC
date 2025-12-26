#include <cstdio>
#include <cstring>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    studentNode *next;
};

void SaveNode(studentNode *child, const char n[], int a, char s, float g);
void GoNext1(studentNode *walk);

int main() {
    studentNode *start, *now1, **now2;

    start = new studentNode;
    SaveNode(start, "one", 6, 'M', 3.11f);

    start->next = new studentNode;
    SaveNode(start->next, "two", 8, 'F', 3.22f);

    start->next->next = new studentNode;
    SaveNode(start->next->next, "three", 10, 'M', 3.33f);

    start->next->next->next = new studentNode;
    SaveNode(start->next->next->next, "four", 12, 'F', 3.44f);

    start->next->next->next->next = nullptr;  // ปิดท้าย list

    now1 = start;
    now2 = &start;

    GoNext1(now1);

    std::printf("After GoNext1 -> now1 = %s\n", now1->name);

    studentNode *cur = start;
    while (cur != nullptr) {
        studentNode *tmp = cur->next;
        delete cur;
        cur = tmp;
    }

    return 0;
}

void SaveNode(studentNode *child, const char n[], int a, char s, float g) {
    std::strcpy(child->name, n);
    child->age = a;
    child->sex = s;
    child->gpa = g;
    child->next = nullptr;
}

void GoNext1(studentNode *walk) {
    if (walk == nullptr) {
        std::printf("walk is NULL\n");
        return;
    }
    if (walk->next == nullptr) {
        std::printf("No next node\n");
        return;
    }

    walk = walk->next; // เปลี่ยนได้แค่ walk ในฟังก์ชัน
    std::printf("Inside GoNext1 -> walk = %s\n", walk->name);
}