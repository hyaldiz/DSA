#include "queue.h"

HndQueue_t createQueue(size_t initialCapacity)
{
    HndQueue_t pQueue = (HndQueue_t)malloc(sizeof(Queue_t));
    if(!pQueue)
    {
        fprintf(stderr,"Queue handler için yeterli alan tahsis edilemedi!\n");
        return NULL;
    }

    pQueue->pItems = (QueueValueType_t*)malloc(sizeof(QueueValueType_t)*initialCapacity);
    if(!pQueue->pItems)
    {
        fprintf(stderr,"Queue memberlar için yeterli alan tahsis edilemedi!\n");
        free(pQueue);
        return NULL;
    }

    pQueue->capacity = initialCapacity;
    pQueue->size = 0;
    pQueue->front = -1;
    pQueue->rear = -1;

    return pQueue;
}

size_t queueSize(HndQueue_t queue)
{
    return queue->size;
}

bool isFull(HndQueue_t queue)
{
    return queue->rear == queue->capacity -1;
}

bool isEmpty(HndQueue_t queue)
{
    return queue->rear == -1;
}

void enQueue(HndQueue_t queue,QueueValueType_t newValue)
{
    if(isFull(queue))
        fprintf(stderr,"enQueue full\n");
    else
    {
        if(queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->pItems[queue->rear] = newValue;
        queue->size++;
    }
}

void deQueue(HndQueue_t queue)
{
    if(isEmpty(queue))
        fprintf(stderr,"deQueue Empty!\n");
    else
    {
        queue->front++;
        queue->size--;
        if(queue->front > queue->rear)
            queue->front = queue->rear = -1;        
    }
}

void printQueue(HndQueue_t queue)
{
    if(isEmpty(queue))
        fprintf(stderr,"printQueue empty!\n");
    else
    {
        for(int index = queue->front;index <= queue->rear;index++)
            printf("%d",queue->pItems[index]);
        printf("\n");
    }
}
