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
    long capacity;
    long size;
}*HndQueue_t,Queue_t;

HndQueue_t createQueue(size_t initialCapacity);
size_t queueSize(HndQueue_t queue);
bool isQueueFull(HndQueue_t queue);
bool isQueueEmpty(HndQueue_t queue);
void enQueue(HndQueue_t queue,QueueValueType_t newValue);
void deQueue(HndQueue_t queue);
void printQueue(HndQueue_t queue);

#endif
