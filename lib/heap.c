#include "./include/heap.h"
#include <stdlib.h>
#include <stdio.h>

static void swap(HeapValueType_t* hval1,HeapValueType_t* hval2)
{
    HeapValueType_t temp = *hval1;
    *hval1 = *hval2;
    *hval2 = temp; 
}

HndHeap_t createHeap(size_t initialCapacity)
{
    HndHeap_t heap = (HndHeap_t)malloc(sizeof(Heap_t));
    if(!heap)
    {
        fprintf(stderr,"Heap Handler Olusturulamadi!");
        return NULL;
    }

    heap->pArray = (HeapValueType_t*)malloc(sizeof(HeapValueType_t)*initialCapacity);
    if(!heap->pArray)
    {
        fprintf(stderr,"Heap array tahsis edilemedi!");
        free(heap);
        return NULL;
    }

    return heap;
}

static void heapify()
{

}