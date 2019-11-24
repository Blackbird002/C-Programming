#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    void *elements;     //Pointer to dynamic array of elements
    int elemSize;       //Size of element in Bytes
    int logLength;      //The actual # of elements
    int allocLength;    //The # of elements in Stack
} Stack;

/*
 *  "Constructor" for the Stack
 *  s is pointer to Stack
 *  elemSize is the size of each element 
 */
void StackNew(Stack *s, int elemSize);

/*
 *  "Desctructor" for the Stack
 *  s is pointer to Stack
 */
void StackDispose(Stack *s);

/*
 *  Pushes an element onto the Stack
 *  s is pointer to Stack
 *  elemAddr is the pointer to element
 */
void StackPush(Stack *s, void *elemAddr);

void StackPop(Stack *s, void *elemAddr);