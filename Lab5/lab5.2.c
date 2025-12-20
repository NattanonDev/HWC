#include <stdio.h>

struct Employee {
    int id;
    int gross_salary;
    int bonus;
    int total_income;
};

/* ประกาศ function */
int calculate_net_salary(int total_income);

int main() {
    struct Employee emp;
    int net_salary;

    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);

    printf("Enter Gross Salary: ");
    scanf("%d", &emp.gross_salary);

    printf("Enter Bonus: ");
    scanf("%d", &emp.bonus);

    /* คำนวณรายได้รวม */
    emp.total_income = emp.gross_salary + emp.bonus;

    /* เรียกใช้ function คำนวณเงินเดือนสุทธิ */
    net_salary = calculate_net_salary(emp.total_income);

    printf("\n--- EMPLOYEE SALARY REPORT ---\n");
    printf("ID: %d\n", emp.id);
    printf("Gross Salary: %d\n", emp.gross_salary);
    printf("Bonus: %d\n", emp.bonus);
    printf("Total Income: %d\n", emp.total_income);
    printf("Net Salary: %d\n", net_salary);

    return 0;
}

/* นิยาม function สำหรับคำนวณเงินเดือนสุทธิ */
int calculate_net_salary(int total_income) {
    float tax_rate;
    int tax_amount;
    int net_salary;

    if (total_income > 30000) {
        tax_rate = 0.10;
    } else {
        tax_rate = 0.05;
    }

    tax_amount = (int)(total_income * tax_rate);
    net_salary = total_income - tax_amount;

    return net_salary;
}