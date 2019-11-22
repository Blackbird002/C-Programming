/*
    Playing with one fork()
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv){
    int num[] = {0,1,2,3,4};
    int status;
    int x = 5;

    printf("Total # of processes = 2^n\n");
    printf("Child & Parent process run in separate memory spaces\n");
    printf("x = %d\n",x);

    printf("Forking one child...\n");
    pid_t pid;
    pid = fork();       //At time of fork(), both memory spaces have same content
    
    if(pid == 0){
        //Child process
        printf("Hey! This is the forked child with pid = %d \n",pid);
        for(int i = 0; i < 5; i++)
            printf(" %d ",num[i]);
        printf("\n");
        x++;
        printf("x = %d\n",x);

        printf("Child will sleep for 3 seconds now...\n");
        sleep(3);
        exit(EXIT_SUCCESS);
    }else if (pid > 0){
        //Parent process
        printf("Hey! I'm the parent process with pid = %d \n",pid);
        for(int i = 0; i < 5; i++)
            printf(" %d ",num[i]);
        printf("\n");
        x++;
        printf("x = %d\n",x);

        if ((pid = wait(&status)) == -1)
            perror("wait() error!");
        else {                     
            if (WIFSIGNALED(status) != 0)
                printf("Child process ended - signal %d\n",WTERMSIG(status));
            else if (WIFEXITED(status) != 0)
                printf("Child process ended normally with status = %d\n",WEXITSTATUS(status));
            else
                printf("Child process did not end normally!\n");
        }
        printf("Parent process ended.n");
    }else{
        printf("Parent reports that there was a -1 returned by fork() call\n");
    }

    return 0;
}