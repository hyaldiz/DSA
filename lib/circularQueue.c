#include "circularQueue.h"

HndCircularQueue_t createCircularQueue(size_t initialCapacity)
{
    HndCircularQueue_t pCircularQueue = (HndCircularQueue_t)malloc(sizeof(CircularQueue_t));
    if(!pCircularQueue)
    {
        fprintf(stderr,"Circular Queue icin yeterli alan tahsis edilemedi!");
        return NULL;
    }

    pCircularQueue->pItems = (CircularQueueValueType*)malloc(sizeof(CircularQueueValueType)*initialCapacity);
    if(!pCircularQueue->pItems)
    {
        fprintf(stderr,"Memberlar icin yeterli alan tahsis edilemedi!");
        free(pCircularQueue);
        return NULL;
    }

    pCircularQueue->front = -1;
    pCircularQueue->rear = -1;
    pCircularQueue->size = 0;
    pCircularQueue->capacity = initialCapacity;

    return pCircularQueue;
}

bool isCircularQueueFull(HndCircularQueue_t cqueue)
{
    if((cqueue->front == cqueue->rear + 1) || (cqueue->front == 0 && cqueue->rear == cqueue->capacity -1))
        return true;
    return false;
}

bool isCircularQueueEmpty(HndCircularQueue_t cqueue)
{
    return cqueue->front == -1;
}

void enCircularQueue(HndCircularQueue_t cqueue, CircularQueueValueType newValue)
{
    if(isCircularQueueFull(cqueue))
        fprintf(stderr,"Circular queue full");
    else
    {
        if(cqueue->front == -1)
            cqueue->front = 0;
        cqueue->rear = (cqueue->rear + 1) % cqueue->capacity;
        cqueue->pItems[cqueue->rear] = newValue;
        cqueue->size++;
    }
}

CircularQueueValueType deCircularQueue(HndCircularQueue_t cqueue)
{
    if(isCircularQueueEmpty(cqueue))
    {
        fprintf(stderr,"Circular queue empty");
        return -1;
    }
    CircularQueueValueType value = cqueue->pItems[cqueue->front];
    if(cqueue->front == cqueue->rear)
        cqueue->front = cqueue->rear = -1;
    else
        cqueue->front = (cqueue->front + 1) % cqueue->capacity;
    return value;
}

void displayCircularQueue(HndCircularQueue_t cqueue)
{
    if(isCircularQueueEmpty(cqueue))
        fprintf(stderr,"Circular queue empty!");
    else
    {
        for(int index = cqueue->front; index != cqueue->rear; index = (index + 1 ) % cqueue->capacity )
            printf("%d --> %d ",index,cqueue->pItems[index]);
    }
}
