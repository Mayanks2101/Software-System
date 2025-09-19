/*
 ============================================================================
 Name        : 24.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to create an orphan process.
 Date        : 31 Aug, 2025
 ============================================================================
*/

// code :

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        printf("Parent process (PID: %d) exiting.\n", getpid());
        exit(0);
    }
    else if (pid == 0) {
        printf("Child process started with PID: %d\n", getpid());
        sleep(5);
        printf("Child process (PID: %d) now has parent PID: %d\n", getpid(), getppid());
        sleep(10);
    }
    else {
        perror("fork failed");
        exit(1);
    }

    return 0;
}

/*
 Output:
 $ ./a.out
 Parent process (PID: 19939) exiting.
 Child process started with PID: 19940
 Child process (PID: 19940) now has parent PID: 2050

*/
