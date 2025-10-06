/*
 * week4_3_struct_database.c
 * Author: Omar Mohamed Ayman Riad Ahmed Zikry
 * Student ID: 231ADB127
 * Description:
 *   Simple in-memory "database" using an array of structs.
 *   Students will use malloc to allocate space for multiple Student records,
 *   then input, display, and possibly search the data.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[100];
    int id;
    float grade;
};

int main(void) {
    int n;
    struct Student *students = NULL;

    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number.\n");
        return 1;
    }

    students = (struct Student *)malloc((size_t)n * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    float totalGrade = 0.0f;
    int topIndex = 0;
    for (int i = 0; i < n; i++) {
        printf("Enter student %d name: ", i + 1);
        if (scanf(" %99[^\n]", students[i].name) != 1) {
            printf("Invalid input for name.\n");
            free(students);
            return 1;
        }

        printf("Enter student %d id: ", i + 1);
        if (scanf("%d", &students[i].id) != 1) {
            printf("Invalid input for id.\n");
            free(students);
            return 1;
        }

        printf("Enter student %d grade: ", i + 1);
        if (scanf("%f", &students[i].grade) != 1) {
            printf("Invalid input for grade.\n");
            free(students);
            return 1;
        }

        totalGrade += students[i].grade;
        if (i == 0 || students[i].grade > students[topIndex].grade) {
            topIndex = i;
        }
    }

    printf("\n%-4s %-20s %-10s %-6s\n", "#", "Name", "ID", "Grade");
    for (int i = 0; i < n; i++) {
        printf("%-4d %-20s %-10d %-6.2f\n", i + 1, students[i].name, students[i].id, students[i].grade);
    }

    // Optional: Compute average grade or find top student
    if (n > 0) {
        float average = totalGrade / (float)n;
        printf("\nAverage grade: %.2f\n", average);
        printf("Top student: %s (ID: %d) Grade: %.2f\n", students[topIndex].name, students[topIndex].id, students[topIndex].grade);
    }

    free(students);

    return 0;
}
