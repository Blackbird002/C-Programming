/*
    A program that spawns multiple threads that calculate 
    F(n) Fibonacci number. Dynamic memory is used
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*
Prints out a hexadecimal representation of pthread_t
https://stackoverflow.com/questions/1759794/how-to-print-pthread-t
*/
void printPt(pthread_t pt) {
    unsigned char *ptc = (unsigned char*)(void*)(&pt);
    printf("0x");
    for (size_t i=0; i<sizeof(pt); i++) {
        printf("%02x", (unsigned)(ptc[i]));
    }
}

// Thread function that calculates Fibonacci numbers 
void* fib_runner(void* arg){

    //cast void* to long long int
    long long int *term = (long long int*) arg;

    int p2, p1 = 0, curr = 1;

    for (long long int i = 1; i <*term ; i++) {
        p2 = p1;
        p1 = curr;
        curr = p2 + p1;
    }

    // Pass back answer in dynamic memory (via pointer)
    long long int *solution = (long long int*)malloc(sizeof(long long int)); 
    *solution = curr;

    // Return with pointer to allocated memory containing solution
    pthread_exit(solution);
}

int main(int argc, char **argv){
    if(argc < 2){
        printf("Usage %s <nth fib #1> <nth fib #2> ... <nth fib #n> \n", argv[0]);
        return -1;
    }

    //Number of arguments (1st one is program name)
    int numArgs = argc - 1;

    //Create array of Thread IDs
    pthread_t thId[numArgs];

    //Create dynamic array of long long ints (for input parameters)
    long long int *term = (long long int*)calloc(numArgs, sizeof(long long int));

    //Run numArg number of threads 
    for(int i = 0; i < numArgs; i++){

        //Convert passed in Cstring argument to long long int
        term[i] = atoll(argv[i+1]);

        //Create thread with default attributes
        pthread_attr_t attr;
        pthread_attr_init(&attr);

        //Create thread and run on fib_runner, passing in term parameter
        pthread_create(&thId[i], &attr, fib_runner, term);
    }

    //Array of long long int pointers
    long long int *answerPtrs[numArgs];

    //Wait for all threads to join...
    for(int i = 0; i < numArgs; i++){
        printf("Main thread waiting for ");printPt(thId[i]);printf("thread to join...\n");
        // pthread_join expects "retval" to be a void ** , casting to void **
        pthread_join(thId[i], (void **)&answerPtrs[i]);    
    }

    for(int i = 0; i < numArgs; i++){
        printf("The F(%lli) Fibonacci number is: %lli \n",atoll(argv[i+1]),*(answerPtrs[i]));

        //Clear allocated memory that element is pointing to
        free(answerPtrs[i]);
    }

    free(term);
    return 0;
}