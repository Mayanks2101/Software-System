/*
 ============================================================================
 Name        : 23.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to create a Zombie state of the running program.
 Date        : 30 Aug, 2025
 ============================================================================
*/

// code :

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        printf("Parent : Process  ID: %d\n", getpid());
        printf("Parent : Child ID: %d\n", pid);
        sleep(20);
    }
    else if (pid == 0) {
        printf("Child process : parent ID: %d\n", getpid());
        exit(0);
    }
    else {
        perror("fork failed");
        exit(1);
    }

    return 0;
}

/*
 Output:
 $./a.out
 Parent : Process  ID: 19878
 Parent : Child ID: 19879
 Child process : parent ID: 19879

 $ ps -el | grep 'Z'
 F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
 1 Z  1000   19879   19878  0  80   0 -     0 -      pts/3    00:00:00 a.out

*/
