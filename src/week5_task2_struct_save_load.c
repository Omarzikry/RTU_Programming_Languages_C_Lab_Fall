// week5_task2_struct_save_load.c
// Task 2: Save and load structured records from a file
// Week 5 – Files & Modular Programming
// TODO: Complete function implementations and file handling logic.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    float gpa;
} Student;

// Function prototypes
void save_student(Student s, const char *filename);
Student load_student(const char *filename);

int main(void) {
    Student s1;
    strcpy(s1.name, "Alice");
    s1.age = 21;
    s1.gpa = 3.75f;

    const char *filename = "student.txt";

    // Save student to file
    save_student(s1, filename);
    // Load back into a new struct
    Student loaded = load_student(filename);
    // Print to confirm correctness
    printf("Loaded Student -> Name: %s, Age: %d, GPA: %.2f\n", loaded.name, loaded.age, loaded.gpa);

    return 0;
}

// TODO: Implement save_student()
// Open file for writing, check errors, write fields, then close file
void save_student(Student s, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Failed to open file for writing");
        return;
    }
    // Write each field on its own line for simplicity
    fprintf(fp, "%s\n", s.name);
    fprintf(fp, "%d\n", s.age);
    fprintf(fp, "%.2f\n", s.gpa);
    fclose(fp);
}

// TODO: Implement load_student()
// Open file for reading, check errors, read fields, then close file
Student load_student(const char *filename) {
    Student s;
    // Initialize with safe defaults
    s.name[0] = '\0';
    s.age = 0;
    s.gpa = 0.0f;

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Failed to open file for reading");
        return s;
    }

    char buffer[128];
    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // Strip trailing newline
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') buffer[len - 1] = '\0';
        strncpy(s.name, buffer, MAX_NAME_LEN - 1);
        s.name[MAX_NAME_LEN - 1] = '\0';
    }
    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        s.age = atoi(buffer);
    }
    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        s.gpa = (float)atof(buffer);
    }

    fclose(fp);
    return s;
}
