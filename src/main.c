#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <dirent.h>
#include <string.h>
#include "../include/io.h"
#include "../include/schedule.h"

int main(void)
{
    struct timeval t0, t1; /* Require time.h */
    float cpu;             /* Running time in seconds */
    unsigned int n, m;
    Task *tasks;
    char filename[280];

    // Open the directory
    DIR *d;
    struct dirent *dir;

    printf("Starting schedule processing with heap...\n");
    printf("Sorting: O(n log n)\n"
           "Initializing: O(m)\n"
           "Scheduling: O(n log m)\n\n");
    d = opendir("./instances");
    if (d)
    {
        // Read files in the directory
        while ((dir = readdir(d)) != NULL)
        {
            // Check if the file is a .dat file
            if (strstr(dir->d_name, ".dat") != NULL)
            {
                // Construct file path
                sprintf(filename, "./instances/%s", dir->d_name);
                // Start timing
                gettimeofday(&t0, NULL);
                // Read task data from file
                read(filename, &n, &m, &tasks);
                // Schedule tasks using heap
                float flowTime = scheduleWithHeap(n, m, tasks);
                // Print file name and total flow time
                printf("File name %s\n", filename);
                printf("Total Flow Time: %f\n", flowTime);
                // Free task array
                free(tasks);
                // End timing
                gettimeofday(&t1, NULL);
                // Calculate and print CPU time
                cpu = ((t1.tv_sec * 1e6 + t1.tv_usec) - (t0.tv_sec * 1e6 + t0.tv_usec)) * 1e-6;
                printf("CPU time: %.3f s.\n\n", cpu);
            }
        }
        closedir(d);
    }
    printf("Finished schedule processing with heap.\n");
    printf("================================================================================\n\n");

    // Repeat the process for schedule function without heap
    printf("Starting schedule processing without heap...\n");
    printf("Sorting: O(n log n)\n"
           "Initializing: O(m)\n"
           "Scheduling: O(nm)\n\n");
    d = opendir("./instances");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            if (strstr(dir->d_name, ".dat") != NULL)
            {
                sprintf(filename, "./instances/%s", dir->d_name);
                gettimeofday(&t0, NULL);
                read(filename, &n, &m, &tasks);
                float flowTime = schedule(n, m, tasks);
                printf("File name %s\n", filename);
                printf("Total Flow Time: %f\n", flowTime);
                // display(n, m, tasks);
                free(tasks);

                gettimeofday(&t1, NULL); 
                cpu = ((t1.tv_sec * 1e6 + t1.tv_usec) - (t0.tv_sec * 1e6 + t0.tv_usec)) * 1e-6;
                printf("CPU time: %.3f s.\n\n", cpu);
            }
        }
        closedir(d);
    }
    printf("Finished schedule processing without heap.\n");
    return 0;
}
