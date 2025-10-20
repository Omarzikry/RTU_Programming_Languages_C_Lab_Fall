// week5_task1_file_io.c
// Task 1: Read and write data from text files
// Week 5 – Files & Modular Programming
// TODO: Fill in the missing parts marked below.

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;
    char filename[100] = "data.txt";
    char line[256];

    // Open file for writing
    fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Failed to open file for writing");
        return 1;
    }
    // Write a few lines
    fprintf(fp, "Hello from Week 5!\n");
    fprintf(fp, "This is a simple file I/O example.\n");
    fprintf(fp, "Each line will be read back and printed.\n");
    // Close the file after writing
    fclose(fp);

    // Open file again for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Failed to open file for reading");
        return 1;
    }
    // Read and print each line; also count the lines
    int lineCount = 0;
    printf("Reading from %s:\n", filename);
    while (fgets(line, sizeof(line), fp) != NULL) {
        fputs(line, stdout);
        lineCount++;
    }
    printf("Total lines read: %d\n", lineCount);
    // Close the file after reading
    fclose(fp);

    // BONUS: ask user for filename instead of using default "data.txt"
    // BONUS: count number of lines read

    return 0;
}
