//parent gets printed out first
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main() {
    int a=0,b=1,c;
    int current_status;
    pid_t rc = fork();  
    if(rc<0){
        perror("fork failed");
        return 1;
    }
    else if (rc == 0) {
        int fact = factorial(4);
        // sleep();/
        printf("Child processes factorial of 4 is %d\n", fact);
        return 0;
    } else if (rc >0) {
        printf("Parent processes the fibonacci series up to 16:\n ");
        for (int i = 0; i < 16; i++) {
            printf("%d ", a);
            c = a+ b;
            a = b;
            b = c;
        }
        printf("\n");
        wait(NULL);
    }   
    return 0;
}
