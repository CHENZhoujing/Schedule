//
// Created by 陈周京 on 13/12/2023.
//

#ifndef SCHEDULE_STRUCTURES_H
#define SCHEDULE_STRUCTURES_H

typedef struct {
    float value;   // 堆中元素的值
    unsigned int index;     // 元素在原始数组中的索引
} HeapNode;


typedef struct {
    unsigned int id;
    float p;
    unsigned int machine;
    float c;
} Task;

#endif //SCHEDULE_STRUCTURES_H
