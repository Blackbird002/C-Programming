#include "Stack.h"
#include <assert.h>
#include <stdio.h>

void testCase1(){
    double num1 = 9.9;
    double num1Pop;
    Stack stack;
    StackNew(&stack, sizeof(double));
    StackPush(&stack,&num1);
    StackPop(&stack,&num1Pop);
    StackDispose(&stack);
    assert(num1 == num1Pop);
    printf("TestCase1 passed!\n");
}

void testCase2(){
    int numbers[10] = {0,1,2,3,4,5,6,7,8,9};
    int numbersPop[10];
    Stack stack;
    StackNew(&stack, sizeof(int));

    for(int i=0; i<10; i++)
        StackPush(&stack,&numbers[i]);

    for(int i=0; i<10; i++)
        StackPop(&stack,&numbersPop[i]);
    
    StackDispose(&stack);

    for(int i=0; i<10; i++){
        assert(numbers[i] == numbersPop[9-i]);
    }
    printf("TestCase2 passed!\n");
}

int main(int argc, char **argv){
    testCase1();
    testCase2();
    printf("All tests passed! \n");
}