//
// Created by 陈周京 on 13/12/2023.
//
#include "../include/schedule.h"
#include "../include/utils.h"

// Function to scheduleWithHeap tasks
float scheduleWithHeap(unsigned int n, unsigned int m, Task *tab) {
    // Sort tasks
    quickSort(tab, 0, n - 1);
    float flowTime = 0.0f;

    // Initialize machine end times
    HeapNode machineEndTime[m];
    int heapSize = 0;

    // Initialize heap with machine end times
    for(unsigned int i = 0; i < m; i++) {
        HeapNode node;
        node.value = 0.0f;
        node.index = i;
        insertHeap(machineEndTime, &heapSize, node);
    }

    // Schedule tasks
    for(int i = 0; i < n; i++) {
        HeapNode node = extractMin(machineEndTime, &heapSize);
        unsigned int minAvailableMachine = node.index;
        node.value += tab[i].p;
        insertHeap(machineEndTime, &heapSize, node);

        tab[i].machine = minAvailableMachine;
        tab[i].c = node.value;
        flowTime += tab[i].c;
    }
    return flowTime;
}

// Function to scheduleWithHeap tasks (alternative method)
float schedule(unsigned int n, unsigned int m, Task *tab) {
    // Sort tasks
    quickSort(tab, 0, n - 1);
    float flowTime = 0.0f;

    // Initialize machine end times
    float machineEndTime[m];
    for(unsigned int i = 0; i < m; i++) {
        machineEndTime[i] = 0.0f;
    }

    // Schedule tasks
    for(int i = 0; i < n; i++) {
        unsigned int minAvailableMachine = findMinEndTimeMachine(machineEndTime, m);
        tab[i].machine = minAvailableMachine;
        machineEndTime[minAvailableMachine] += tab[i].p;
        tab[i].c = machineEndTime[minAvailableMachine];
        flowTime += tab[i].c;
    }
    return flowTime;
}