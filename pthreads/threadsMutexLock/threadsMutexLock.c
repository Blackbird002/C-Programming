/*
    A program that spawns multiple threads that adds 1 term times
    and then subtracts 1 term times.
    -Dynamic memory is used
    -Mutex lock is used
    -Critical Section
    -Shared resource
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h> 
#include <assert.h>

typedef struct{
    long long int term;
    unsigned long long solution;
} fibStruct;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

//Create dynamic array of fibStruct pointers
fibStruct *globalFibStructs;

//Index of next free spot in globalFibStructures
int currentIndex = 0;

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

// Something that will take some time...
void* sum_runner(void* arg){
    pid_t tid = syscall(SYS_gettid);

    //cast void* to long long int
    long long int *term = (long long int*) arg;

    unsigned long long int sum = 0;

    for (long long int i = 1; i <=*term ; i++)
       sum++;

    for (long long int i = 1; i <=*term ; i++)
       sum--;

    // The Critical Section
    //*************************************************************************************
    pthread_mutex_lock(&mutex);
    printf("Thread "); printPt(tid); printf(" locked shared resource... \n");
    globalFibStructs[currentIndex].term = *term;
    globalFibStructs[currentIndex].solution = sum;

    //Increment index
    currentIndex++;

    printf("Thread "); printPt(tid); printf(" is about to unlock shared resource... \n");
    pthread_mutex_unlock(&mutex);
    //*************************************************************************************

    // Return 
    pthread_exit(NULL);
}

int main(int argc, char **argv){
    if(argc < 2){
        printf("Usage %s <nth fib #1> <nth fib #2> ... <nth fib #n> \n", argv[0]);
        return -1;
    }

    // Number of arguments (1st one is program name)
    int numArgs = argc - 1;

    // Dynamic array of fibStructs
    globalFibStructs = (fibStruct*)calloc(numArgs,sizeof(fibStruct));

    // Dynamic array of long long ints
    long long int *terms = (long long int*)calloc(numArgs,sizeof(long long int));

    // Create array of Thread IDs
    pthread_t *thId = (pthread_t*)calloc(numArgs,sizeof(pthread_t));

    // Check if calloc failed...
    if(globalFibStructs == NULL || terms == NULL || thId == NULL)
        return -1;

    //Run numArg number of threads 
    for(int i = 0; i < numArgs; i++){

        // Convert passed in Cstring argument to long long int
        terms[i] = atoll(argv[i+1]);

        // Create thread with default attributes
        pthread_attr_t attr;
        pthread_attr_init(&attr);

        // Create thread and run on fib_runner, passing in term parameter
        pthread_create(&thId[i], &attr, sum_runner, &terms[i]);
    }

    // Wait for all threads to join...
    for(int i = 0; i < numArgs; i++){
        printf("Main thread waiting for ");printPt(thId[i]);printf(" thread to join...\n");
        pthread_join(thId[i], NULL);    
    }

    printf("Checking if terms[i] == globalStructs[i].term & if all globalStructs[i].solution == 0 \n");
    for(int i = 0; i < numArgs; i++){
        assert(terms[i] == globalFibStructs[i].term);
        assert(globalFibStructs[i].solution == 0);
    }
    printf("Correct! \n");
    
    //Free memory used
    free(globalFibStructs);
    free(terms);
    free(thId);
 
    return 0;
}