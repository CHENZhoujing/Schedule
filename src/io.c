//
// Created by 陈周京 on 13/12/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "../include/io.h"

// Function to read task data from a file
void read(char* filename, unsigned int *n, unsigned int *m, Task **tab) {
    // Open the file
    FILE *file = fopen(filename, "r");
    // Error handling for file opening
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    // Read two unsigned integers from the file
    if (fscanf(file, "%u %u\n", n, m) != 2) {
        // 错误处理代码，例如打印错误消息并退出
        fprintf(stderr, "Error reading from file.\n");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for the task array
    *tab = (Task *) malloc(*n * sizeof(Task));
    // Error handling for memory allocation
    if (*tab == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return;
    }
    // Read data for each task
    for (unsigned int i = 0; i < *n; i++) {
        // Set task ID
        (*tab)[i].id = i + 1;
        // Read the p value for the task from the file
        if (fscanf(file, "%f", &((*tab)[i].p)) != 1) {
            // 错误处理代码
            fprintf(stderr, "Error reading float from file at line %d.\n", i);
            exit(EXIT_FAILURE);
        }

        // Initialize the machine number for the task
        (*tab)[i].machine = 0;
        // Initialize the c value for the task
        (*tab)[i].c = -1;
    }
    // Close the file
    fclose(file);
}
