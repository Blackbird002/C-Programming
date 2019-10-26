/*
 Reading from a file using fgets() test
*/
#include <stdio.h>
#include <assert.h>
#include <string.h>

#define LINELEN 1024    //Max length of a line is 1024 chars (bytes)

/*
strlen()
The length of a C string is determined by the terminating null-character: A C string is as long as the number of characters between the beginning of 
the string and the terminating null character (without including the terminating null character itself).
*/

int usefgets(int getRidOfNewLine){
    FILE *fp;
    char line[LINELEN];
    char* filename = "file.txt";

    //These are for our reference...
    char test[3][20] = {
        {'f','a','c','e','b','o','o','k','.','c','o','m','\0'},
        {'g','o','o','g','l','e','.','c','o','m','\0'},
        {'a','m','a','z','o','n','.','c','o','m','\0'},
    };

    //Open for reading...
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }

    int i = 0;
    int sizeOfCStr = 0;
    int sizeWeWant = 0;
    while (fgets(line, LINELEN, fp) != NULL){
        printf("Line#%i contains: %s",i,line);

        //If it's 1 we will get rid of the newline char:
        if(getRidOfNewLine == 1){
            char *pos;
            if ((pos=strchr(line, '\n')) != NULL)
                *pos = '\0';
        }
        sizeOfCStr = strlen(line);
        printf("Size of C-String = %i\n",sizeOfCStr);
        sizeWeWant = strlen(test[i]);
        printf("Size should be = %i\n",sizeWeWant);
        i++;
    }
    fclose(fp);
    return 0;
}

int main(int argc, char **argv){
    printf("Without removing newline character...\n");
    if(usefgets(0)){
        printf("Error occured in usefgets() function!\n");
    }
    printf("\n");
    printf("Removing newline character...\n");
    if(usefgets(1)){
        printf("Error occured in usefgets() function!\n");
    }

    return 0;
}