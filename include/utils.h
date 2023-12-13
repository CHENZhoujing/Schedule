//
// Created by 陈周京 on 13/12/2023.
//

#ifndef SCHEDULE_UTILS_H
#define SCHEDULE_UTILS_H

#include "structures.h"

void display(unsigned int n, unsigned int m, Task *tab);

void swap(Task *a, Task *b);
int partition(Task *tab, int left, int right);
void quickSort(Task *tab, int left, int right);

unsigned int findMinEndTimeMachine(float machineEndTime[], unsigned int m);

void heapify(HeapNode heap[], int size, int i);
HeapNode extractMin(HeapNode heap[], int *size);
void insertHeap(HeapNode heap[], int *size, HeapNode node);

#endif //SCHEDULE_UTILS_H
