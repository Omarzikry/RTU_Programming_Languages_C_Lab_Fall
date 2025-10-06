/*
 * week4_2_struct_student.c
 * Author: Omar Mohamed Ayman Riad Ahmed Zikry
 * Student ID: 231ADB127
 * Description:
 *   Demonstrates defining and using a struct in C.
 *   Students should define a 'Student' struct with fields like name, id, and grade.
 *   Then create a few instances and print them.
 */

#include <stdio.h>
#include <string.h>

// Define struct Student with fields: name (char[]), id (int), grade (float)
struct Student {
    char name[50];
    int id;
    float grade;
};

int main(void) {
    // Declare Student variables
    struct Student student1 = {"Alice Johnson", 101, 92.5f};
    struct Student student2;

    // Assign values (manually)
    strcpy(student2.name, "Bob Smith");
    student2.id = 102;
    student2.grade = 85.0f;

    // Print struct contents
    printf("Student 1 -> Name: %s, ID: %d, Grade: %.2f\n", student1.name, student1.id, student1.grade);
    printf("Student 2 -> Name: %s, ID: %d, Grade: %.2f\n", student2.name, student2.id, student2.grade);

    return 0;
}
