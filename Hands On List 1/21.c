/*
 ============================================================================
 Name        : 21.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program, call fork and print the parent and child process id.
 Date        : 30 Aug, 2025
 ============================================================================
*/

// code :

#include <stdio.h>
#include <unistd.h>  // For fork()
#include <sys/types.h> // For pid_t

int main() {
    pid_t pid;

    pid = fork();

    perror("Fork : ");   

    if (pid == 0) {
        printf("Child Process: PID is %d, Parent PID is %d\n", getpid(), getppid());
    } 
    else {
        printf("Parent Process: PID is %d, Child PID is %d\n", getpid(), pid);
    }

    return 0;
}

/*
 Output:
 $ ./a.out
 Fork : : Success
 Parent Process: PID is 19768, Child PID is 19769
 Fork : : Success
 Child Process: PID is 19769, Parent PID is 19768
*/
