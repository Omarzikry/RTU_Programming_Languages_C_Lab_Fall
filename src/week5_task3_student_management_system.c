// week5_task3_student_management_system.c
// Task 3: Mini-project – Student management system with file persistence
// Week 5 – Files & Modular Programming
// TODO: Implement functions to load, save, add, and list students.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50
#define DATA_FILE "students.txt"

typedef struct {
    char name[NAME_LEN];
    int id;
    float gpa;
} Student;

// Function prototypes
int load_students(Student arr[]);
void save_students(Student arr[], int count);
void add_student(Student arr[], int *count);
void list_students(Student arr[], int count);

int main(void) {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    // Load existing data
    count = load_students(students);
    printf("Loaded %d student(s) from %s.\n", count, DATA_FILE);

    do {
        printf("\n=== Student Management System ===\n");
        printf("1. List students\n");
        printf("2. Add student\n");
        printf("3. Save and Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                list_students(students, count);
                break;
            case 2:
                add_student(students, &count);
                break;
            case 3:
                save_students(students, count);
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// TODO: Implement load_students()
// Open DATA_FILE, read records until EOF, return number of records loaded
int load_students(Student arr[]) {
    FILE *fp = fopen(DATA_FILE, "r");
    if (fp == NULL) {
        // No existing file; start fresh
        return 0;
    }
    int count = 0;
    while (count < MAX_STUDENTS) {
        Student s;
        // Expect format: name\nid\ngpa\n per record
        char nameBuf[NAME_LEN];
        if (fgets(nameBuf, sizeof(nameBuf), fp) == NULL) break;
        size_t len = strlen(nameBuf);
        if (len > 0 && nameBuf[len - 1] == '\n') nameBuf[len - 1] = '\0';
        strncpy(s.name, nameBuf, NAME_LEN - 1);
        s.name[NAME_LEN - 1] = '\0';
        if (fscanf(fp, "%d\n", &s.id) != 1) break;
        if (fscanf(fp, "%f\n", &s.gpa) != 1) break;
        arr[count++] = s;
    }
    fclose(fp);
    return count;
}

// TODO: Implement save_students()
// Write all students to DATA_FILE
void save_students(Student arr[], int count) {
    FILE *fp = fopen(DATA_FILE, "w");
    if (fp == NULL) {
        perror("Failed to open data file for writing");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s\n", arr[i].name);
        fprintf(fp, "%d\n", arr[i].id);
        fprintf(fp, "%.2f\n", arr[i].gpa);
    }
    fclose(fp);
    printf("Saved %d student(s) to %s.\n", count, DATA_FILE);
}

// TODO: Implement add_student()
// Read input from user and append to array
void add_student(Student arr[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Cannot add more students; storage is full.\n");
        return;
    }
    Student s;
    printf("Enter name: ");
    if (fgets(s.name, sizeof(s.name), stdin) == NULL) return;
    size_t len = strlen(s.name);
    if (len > 0 && s.name[len - 1] == '\n') s.name[len - 1] = '\0';
    printf("Enter id: ");
    if (scanf("%d", &s.id) != 1) {
        printf("Invalid id.\n");
        // clear input
        int c; while ((c = getchar()) != '\n' && c != EOF) {}
        return;
    }
    printf("Enter gpa: ");
    if (scanf("%f", &s.gpa) != 1) {
        printf("Invalid GPA.\n");
        int c; while ((c = getchar()) != '\n' && c != EOF) {}
        return;
    }
    // clear newline after scanf
    int c; while ((c = getchar()) != '\n' && c != EOF) {}
    arr[*count] = s;
    (*count)++;
    printf("Student added. Current count: %d\n", *count);
}

// TODO: Implement list_students()
// Print all students in readable format
void list_students(Student arr[], int count) {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }
    printf("\n-- Students --\n");
    for (int i = 0; i < count; i++) {
        printf("%d) Name: %s | ID: %d | GPA: %.2f\n", i + 1, arr[i].name, arr[i].id, arr[i].gpa);
    }
}
