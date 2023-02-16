#include <stdlib.h>
#include "stack.h"

int main()
{
    HndStack_t testStack = createEmptyStack(10);

    //test1
    /*if(isEmpty(testStack))
        printf("Stack bos!\n");
    else
        printf("Stack bos degil!\n");

    push(testStack,1);

    if(isEmpty(testStack))
        printf("Stack bos\n");
    else
        printf("Stack bos degil!\n");

    pop(testStack);

    if(isEmpty(testStack))
        printf("Stack bos\n");
    else
        printf("Stack bos degil!\n");*/

    //test2
    /*push(testStack,1);
    push(testStack,2);
    push(testStack,3);
    push(testStack,4);
    push(testStack,5);
    push(testStack,6);
    push(testStack,7);
    push(testStack,8);
    push(testStack,9);
    push(testStack,10);
    push(testStack,11);
    push(testStack,12);*/

    //test3
    //pop(testStack);

    //test4
    /*push(testStack,1);
    push(testStack,2);

    printStack(testStack);
    printf("%ld",stackSize(testStack));*/

    //test5
    /*printf("%d\n",peek(testStack));
    push(testStack,10);
    printf("%d\n",peek(testStack));*/

    return EXIT_SUCCESS;
}
