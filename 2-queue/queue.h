#ifndef QUEUE_H
#define QUEUE_H

//First In First Out (FIFO)
//Programlama açısından queue'ya eleman eklemeye enqueue eleman çıkarmaya dequeue denir.

/*
    Basic Operations of Queue
        * Enqueue : Add an element to the end of the queue
        * Dequeue : Remove an element from the front of the queue
        * IsEmpty : Check if the queue is empty
        * IsFull : Check if the queue is full
        * Peek : Get the value of the front of the queue without removing it
*/

/*
    Limitations of Queue    
        * As you can see in the image below, after a bit of 
          enqueuing and dequeuing, the size of the queue has been reduced.
*/

/*
    Complexity Analysis
        * The complexity of enqueue and dequeue operations in a queue using an array is O(1). 
          If you use pop(N) in python code, then the complexity might be O(n) depending on the position of the item to be popped.
*/

/*
    Applications of Queue
        * CPU scheduling, Disk Scheduling
        * When data is transferred asynchronously between two processes.The queue is used for synchronization. For example: IO Buffers, pipes, file IO, etc
        * Handling of interrupts in real-time systems.
        * Call Center phone systems use Queues to hold people calling them in order.
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef int QueueValueType_t;

typedef struct Queue
{
    QueueValueType_t* pItems;
    long front;
    long rear;
    size_t capacity;
    size_t size;
}*HndQueue_t,Queue_t;

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
    if(queue->rear == queue->capacity -1)
        return true;
    return false;
}

bool isEmpty(HndQueue_t queue)
{
    if(queue->rear == -1)
        return true;
    return false;
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

#endif