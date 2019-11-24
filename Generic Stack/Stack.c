#include "Stack.h"

/*
 *  Double the amount of allocated space
 *  static in C means it's a "private function"
 */
static void StackDouble(Stack *s){
    assert(s->elements != NULL);
    s->allocLength *= 2;
    //realloc changes the size of memory block 
    s->elements = realloc(s->elements, s->allocLength * s->elemSize);
}

void StackNew(Stack *s, int elemSize){
    //Check if client passed in < 0 elemSize
    s->elemSize = elemSize;
    s->logLength = 0;
    s->allocLength = 4;
    s->elements = malloc(4 * elemSize);
    //Check if space was allocated
    assert(s->elements != NULL);
}

void StackDispose(Stack *s){
    free(s->elements);
}

void StackPush(Stack *s, void *elemAddr){
    assert(s->elements != NULL);
    if(s->logLength == s->allocLength)
        StackDouble(s);

    //Sets targer ptr to point to the next spot in stack
    void *target = (char*)s->elements + s->logLength * s->elemSize;

    memcpy(target,elemAddr,s->elemSize);
    s->logLength++;
}

void StackPop(Stack *s, void *elemAddr){
    assert(s->elements != NULL);
    void *source = (char*)s->elements + (s->logLength-1) * s->elemSize;
    memcpy(elemAddr,source,s->elemSize);
    s->logLength--;
}