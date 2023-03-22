#include "./include/stack.h"

HndStack_t createStack(size_t initialCapacity)
{
    HndStack_t pStack = (HndStack_t)malloc(sizeof(Stack_t));
    if(!pStack)
    {
        fprintf(stderr,"Stack Handler icin yeterli alan tahsis edilemedi!\n");
        return NULL;
    }

    pStack->pItems = (ValueType_t*)malloc(sizeof(ValueType_t)*initialCapacity);
    if(!pStack->pItems)
    {
        fprintf(stderr,"Stack Memberları icin yeterli alan tahsis edilemedi!\n");
        free(pStack);
        return NULL;
    }

    pStack->size = 0;
    pStack->capacity = initialCapacity;
    pStack->top = -1;
    return pStack;
}

size_t stackSize(HndStack_t stack)
{
    return stack->size;
}

bool isStackFull(HndStack_t stack)
{
    return stack->top == stack->capacity -1;
}

bool isStackEmpty(HndStack_t stack)
{
    return stack->top == -1;
}

void push(HndStack_t stack,ValueType_t newItem)
{
    if(isStackFull(stack))
        fprintf(stderr,"Push Stack dolu!\n");
    else
    {
        stack->top++;
        stack->size++;
        stack->pItems[stack->top] = newItem;
    }
}

void pop(HndStack_t stack)
{
    if(isStackEmpty(stack))
        fprintf(stderr,"Pop Stack Bos!\n");
    else
    {
        stack->top--;
        stack->size--;        
    }
}

ValueType_t peek(HndStack_t stack)
{
    if(isStackEmpty(stack))
    {
        fprintf(stderr,"Peek Stack Bos!\n");
        return -1;
    }    
    return stack->pItems[stack->top];
}

void printStack(HndStack_t stack)
{
    for(int index=0;index<stack->size;index++)
        printf("index(%d):%d ",index,stack->pItems[index]);
    printf("\n");
}
