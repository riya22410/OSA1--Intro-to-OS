*************** Description of Q1 part (i) ***********************
This code demonstrates a simple example of using fork() and wait() system calls in a C program to create a child process and manage its 
execution. 

1. The necessary header files are included: `stdio.h`, `stdlib.h`, `unistd.h`, and `sys/wait.h`. These provide functions and definitions for 
input/output operations, memory allocation, process management, and waiting for child processes.

2. The `main` function starts by declaring a variable `rc` of type `pid_t`, which will store the process ID returned by the `fork` system 
call. `fork` creates a new process by duplicating the current process. If the return value `rc` is negative, an error occurred, so an error
message is printed and the program returns with a status of 1.

3. If `rc` is 0, it means the `fork` call was successful and the code block inside the `if` statement is executed. This block belongs to the 
child process. The child process prints its own process ID using `getpid()`, and also prints the parent process's ID using `getppid()`.

4. If `rc` is positive and not 0, it means the `fork` call was successful and the code block inside the `else` statement is executed. 
This block belongs to the parent process. The parent process prints its own process ID using `getpid()`. It then calls the `wait` system 
call using `wait(NULL)`. This call suspends the parent process until any of its child processes terminate. The return value of 
`wait` (stored in `wc`) is not used in this case.

5. After the child process terminates, the parent process resumes execution. It prints the process ID of the child process, which is the 
value of `rc`.

6. Finally, the `main` function returns 0, indicating successful execution.

To summarize, this code creates a child process using the `fork` system call. The parent and child processes execute separate code blocks 
after the fork. The parent process waits for the child process to terminate before printing its child's process ID. The child process prints 
its own process ID and the parent's process ID.
