#ifndef HEAP_H
#define HEAP_H

#include <stddef.h>

typedef int HeapValueType_t;

typedef struct Heap
{
    HeapValueType_t* pArray;
}*HndHeap_t,Heap_t;


HndHeap_t createHeap(size_t initialCapacity);



#endif
