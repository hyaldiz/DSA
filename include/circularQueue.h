#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef int CircularQueueValueType;

typedef struct CircularQueue
{
    CircularQueueValueType* pItems;
    long front;
    long rear;
    long size;
    long capacity;
}*HndCircularQueue_t , CircularQueue_t;

HndCircularQueue_t createCircularQueue(size_t initialCapacity);

bool isCircularQueueFull(HndCircularQueue_t cqueue);
bool isCircularQueueEmpty(HndCircularQueue_t cqueue);
void enCircularQueue(HndCircularQueue_t cqueue,CircularQueueValueType newValue);
CircularQueueValueType deCircularQueue(HndCircularQueue_t cqueue);

#endif // CIRCULARQUEUE_H
