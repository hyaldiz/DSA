#include "queue.h"


int main()
{
    HndQueue_t testQueue = createQueue(10);

    deQueue(testQueue);

    if(isEmpty(testQueue))  printf("Empty!\n");
    if(isFull(testQueue))   printf("Full\n");

    enQueue(testQueue,1);

    if(isEmpty(testQueue))  printf("Empty!\n");
    if(isFull(testQueue))   printf("Full\n");

    printf("Size --> %ld\n",queueSize(testQueue));

    enQueue(testQueue,1);
    enQueue(testQueue,1);
    enQueue(testQueue,1);
    enQueue(testQueue,1);
    enQueue(testQueue,1);
    enQueue(testQueue,1);
    enQueue(testQueue,1);
    enQueue(testQueue,1);
    enQueue(testQueue,1);

    printf("Size --> %ld\n",queueSize(testQueue));

    if(isFull(testQueue))   printf("Full xx\n");

    enQueue(testQueue,1);

    printf("Size --> %ld\n",queueSize(testQueue));

    deQueue(testQueue);

    printf("Size --> %ld\n",queueSize(testQueue));

    return EXIT_SUCCESS;
}   