#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(int argc, char *argv[])
{
    pid_t rc=fork();
    if(rc<0)
    {
        perror("fork");
        return 1;
    }
    else if(rc==0) //child - new process
    {
        printf("C) Child is having ID: %d \n", getpid());
        printf("D) My parent ID is: %d \n", (int) getppid());
    }
    else //parent process
    {
        printf("A) Parent (P) is having ID: %d \n", (int) getpid());
        int wc= wait(NULL);
        printf("B) ID of P's Child is %d", rc);
    }
    return 0;
}

