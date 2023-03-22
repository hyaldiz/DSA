#include <stdio.h>
#include "./include/heap.h"

int main()
{
    HndHeap_t testHeap = createHeap(15);
    
    if(testHeap)
        printf("Heap created successfuly\n");

    return 0;
}