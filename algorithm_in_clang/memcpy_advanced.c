#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define NEWLINE printf("\n");

typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

void update_employee_name(Employee *emp, const char *new_name) {
    memcpy(emp->name, new_name, strlen(new_name) + 1); // +1 for null terminator
}

uint32_t reverse_endian(uint32_t value) {
    uint32_t reversed;
    char *src = (char *)&value;
    char *dest = (char *)&reversed;

    for (size_t i = 0; i < sizeof(uint32_t); ++i) {
        dest[i] = src[sizeof(uint32_t) - 1 - i];
    }

    return reversed;
}

int main() {
    // 従業員の初期化
    Employee emp = {1, "Alice", 50000.0};

    // 従業員の名前を更新
    update_employee_name(&emp, "Capi");

    // 更新後の従業員の情報を表示
    printf("ID: %d\n", emp.id);
    printf("Name: %s\n", emp.name);
    printf("Salary: %.2f\n", emp.salary);
    NEWLINE;

    emp.salary = 200;
    printf("ID: %d\n", emp.id);
    printf("Name: %s\n", emp.name);
    printf("Salary: %.2f\n", emp.salary);
    NEWLINE;


    // リトルエンディアンへの変換
    uint32_t original = 0x12345678;
    uint32_t reversed = reverse_endian(original);

    printf("Original: 0x%08X\n", original);
    printf("Reversed: 0x%08X\n", reversed);

    return 0;
}