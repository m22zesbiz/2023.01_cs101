#include <stdio.h>
#include <string.h>

#define employee_info(arr) { \
    printf("Employee Info: \n"); \
    printf("ID: %d\n", arr.em_id); \
    printf("Name: %s\n", arr.em_name); \
    printf("Age: %d\n", arr.em_age); \
    printf("Phone: %s\n", arr.em_phone); \
    printf("Salary: %.2f\n", arr.em_salary);  \
}

typedef struct Employee {
    int em_id; 
    char em_name[10]; 
    int em_age; 
    char em_phone[12]; 
    float em_salary; 
} employee_t; 

int main() {
    employee_t a; 
    a.em_id = 22; 
    strcpy(a.em_name, "IU Lee");
    a.em_age = 18; 
    strcpy(a.em_phone, "0937123456");
    a.em_salary = 1000.30; 

    printf("%d\n", (int)sizeof(employee_t)); 
    employee_info(a);
}
