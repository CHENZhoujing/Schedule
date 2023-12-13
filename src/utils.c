//
// Created by 陈周京 on 13/12/2023.
//
#include <printf.h>
#include <float.h>
#include "../include/utils.h"

// Function to display task details
void display(unsigned int n, unsigned int m, Task *tab) {
    printf("Number of tasks: %u\n", n);
    printf("Number of machines: %u\n", m);
    for (unsigned int i = 0; i < n; i++) {
        printf("Task %u: Pi %f, Machine %u, Completion Time: %.2f\n",
               tab[i].id, tab[i].p, tab[i].machine, tab[i].c);
    }
}

// Function to sort tasks using QuickSort
void quickSort(Task *tab, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(tab, left, right);
        quickSort(tab, left, pivotIndex - 1);
        quickSort(tab, pivotIndex + 1, right);
    }
}

// Function to partition the array for QuickSort
int partition(Task *tab, int left, int right) {
    float pivot = tab[right].p;
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (tab[j].p < pivot) {
            i++;
            swap(&tab[i], &tab[j]);
        }
    }
    swap(&tab[i + 1], &tab[right]);
    return i + 1;
}

// Function to swap two tasks
void swap(Task *a, Task *b) {
    Task temp = *a;
    *a = *b;
    *b = temp;
}

// Function to find the machine with the minimum end time
unsigned int findMinEndTimeMachine(float machineEndTime[], unsigned int m){
    float minValue = FLT_MAX;
    int minAvailableMachine = 0;
    for(int i = 0; i < m; i++){
        if(machineEndTime[i] < minValue) {
            minValue = machineEndTime[i];
            minAvailableMachine = i;
        }
    }
    return minAvailableMachine;
}

// Function to maintain heap property
void heapify(HeapNode heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left].value < heap[smallest].value)
        smallest = left;

    if (right < size && heap[right].value < heap[smallest].value)
        smallest = right;

    if (smallest != i) {
        HeapNode temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        heapify(heap, size, smallest);
    }
}

// Function to extract minimum node from heap
HeapNode extractMin(HeapNode heap[], int *size) {
    HeapNode minNode = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapify(heap, *size, 0);
    return minNode;
}

// Function to insert a node into heap
void insertHeap(HeapNode heap[], int *size, HeapNode node) {
    heap[*size] = node;
    int i = *size;
    (*size)++;

    while (i != 0 && heap[(i - 1) / 2].value > heap[i].value) {
        HeapNode temp = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = heap[i];
        heap[i] = temp;
        i = (i - 1) / 2;
    }
}