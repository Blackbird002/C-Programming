/*
 Generic Swap Function
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void swap(void *vp1, void *vp2, int size);
void test();

int main(){
    test();
    return 0;
}

/*
-size is # of Bytes of figure being swapped
*/
void swap(void *vp1, void *vp2, int size){
    //A char is 1 Byte...
    char *buffer = (char*)malloc(size);
    //Byte by Byte copy of memory
    memcpy(buffer,vp1,size);
    memcpy(vp1,vp2,size);
    memcpy(vp2,buffer,size);
    free(buffer);
}

void test(){
    printf("Running Tests...\n");

    //int Type
    int x = 5;
    int y = 23;
    swap(&x,&y,sizeof(int));
    assert(x == 23);
    assert(y == 5);

    //double Type
    double a = 5.5;
    double b = 3.1415;
    swap(&a,&b,sizeof(double));
    assert(a == 3.1415);
    assert(b == 5.5);

    //struct student Type
    struct student{
        char name[50];
        double gpa;
    };
    char name1[] = "John Smith";
    char name2[] = "Sam Jones";

    struct student stu1,stu2;
    strcpy(stu1.name,name2);
    stu1.gpa = 4.00;
    strcpy(stu2.name,name1);
    stu2.gpa = 3.88;

    swap(&stu1,&stu2,sizeof(struct student));

    assert(strcmp(stu1.name,name1)==0);
    assert(stu1.gpa == 3.88);
    assert(strcmp(stu2.name,name2)==0);
    assert(stu2.gpa == 4.00);

    printf("All tests Passed!\n");
}