/*
 Generic Linear Search Function
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void *lSearch(void *key, void *base, int n, int elemSize, int (*cmpFunc)(void *, void *));

//Typical sample client functions to compare types...
int intCmp(void *elem1, void *elem2);
int doubleCmp(void *elem1, void *elem2);

void test();

int main(){
    test();
    return 0;
}

int intCmp(void *elem1, void *elem2){
    int *iptr1 = elem1;
    int *iptr2 = elem2;
    //dereference as an integer and subtract
    return *iptr1 - *iptr2;
}

int doubleCmp(void *elem1, void *elem2){
    double *iptr1 = elem1;
    double *iptr2 = elem2;
    if(*iptr1 - *iptr2 == 0.0)
        return 0;
    else
        return -1;
}

/*
 - key: the thing we are searching for
 - base: is the start of the array
 - n: # of elements
 - elemSize: the size (in Bytes) of the elements
 - cmpFunc: pointer to a client comparison function
*/
void *lSearch(void *key, void *base, int n, int elemSize, int(*cmpFunc)(void *, void *)){
    for(int i = 0; i < n; i++){
        //need to manually compute the address of the ith element...
        void *elemAddr = (char*)base + (i * elemSize);
        if(cmpFunc(key,elemAddr)==0)
            return elemAddr;
    }
    return NULL;
}

//Test type int
void case1(){
    int arr[] = {3,32,55,2,-4,9,5};
    int size = 7;
    int num = 9;

    int *found = lSearch(&num, arr,size,sizeof(int),intCmp);
    assert(*found == 9);
}

//Test type double
void case2(){
    double arr[] = {1.123, 7.9, 100.101, 203.34, 2.2, 0.1, 0.9999, 3.1415, 5.01, 0.0};
    double size = 10;
    double num = 3.1415;

    double *found = lSearch(&num, arr,size,sizeof(double),doubleCmp);
    assert(*found == 3.1415);
}

//Test not found
void case3(){
    int arr[] = {3,32,55,2,-4,9,5};
    int size = 7;
    int num = 100;

    int *found = lSearch(&num, arr,size,sizeof(int),intCmp);
    assert(found == NULL);
}

void test(){
    printf("Running Tests...\n");
    case1();
    case2();
    case3();
    printf("All tests Passed!\n");
}