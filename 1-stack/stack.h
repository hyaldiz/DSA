#ifndef STACK_H
#define STACK_H

//Last In First Out Principle (LIFO)
//Programlama açısından stack'in üzerine eleman koymaya push eleman çıkarmaya ise pop denir.

/*
    Basic Operations of Stack
        * Push : Add an element to the top of a stack
        * Pop : Remove an element from the top of a stack
        * IsEmpty : Check is the stack is empty
        * IsFull : Check if the stack is full
        * Peek : Get the value of the top element without removing it
*/

/*
    Stack Time Complexity
        push ve pop işlemleri Constant Time O(1)

*/

/*
    Applications of Stack Data Structure
        * To reverse a word
            -Put all the letters in a stack and pop them out. 
             Because of the LIFO order of stack, you will get the letters in reverse order.
        * In Compilers
            - Compilers use the stack to calculate the value of expressions 
              like 2 + 4 / 5 * (7 - 9) by converting the expression to prefix or postfix form.
        * In Browsers
            - The back button in a browser saves all the URLs you have visited previously in a stack.
              Each time you visit a new page, it is added on top of the stack. 
              When you press the back button, the current URL is removed from the stack, and the previous URL is accessed.
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef int ValueType_t;

typedef struct Stack
{
    ValueType_t* pItems;
    size_t capacity;
    size_t size;
    long top;
}*HndStack_t,Stack_t;

HndStack_t createEmptyStack(size_t initialCapacity);
size_t stackSize(HndStack_t stack);
bool isFull(HndStack_t stack);
bool isEmpty(HndStack_t stack);
void push(HndStack_t stack,ValueType_t newItem);
void pop(HndStack_t stack);
ValueType_t peek(HndStack_t stack);
void printStack(HndStack_t stack);

#endif