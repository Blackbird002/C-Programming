/*
 Convert a string to a number using strtol
*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h> 
#include <limits.h>
#include <assert.h> 

int convertToLong(char *str){
    errno = 0;
    char *endptr;
    /* 
    long int strtol (const char* str, char** endptr, int base);

    Convert string to long integer
    Reference to an object of type char*, whose value is set by the function to the next
    character in str after the numerical value. 
    */
    long val = strtol(str, &endptr, 10);
    if (errno == ERANGE) {
        switch(val) {
        case LONG_MIN:
            printf("We have an underflow!\n");
            break;
        case LONG_MAX:
            printf("We have an overflow!\n");
            break;
        default:
            assert(false);
        }
    } else if (errno != 0) {
        printf("Error!\n");
        return 1;
    } else if (*endptr != '\0') {
        printf("This is the garbage at the end of the CString: %s\n",endptr);
    }
    printf("This is the result %i",val);
}

int main(int argc, char **argv){
    printf("argv[1] = %s\n",argv[1]);
    if(convertToLong(argv[1])){
        printf("Error in convertToLong(char *str)!\n");
    }
    return 0;
}