/*
 ============================================================================
 Name        : 18.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to find out total number of directories on the pwd.
               execute ls -l | grep ^d | wc ? Use only dup2.
 Date        : 06 Sep, 2025
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipe1[2], pipe2[2];
    pid_t pid1, pid2;

    pipe(pipe1);
    pid1 = fork();

    if (pid1 == 0) {
        close(pipe1[0]);
        dup2(pipe1[1], 1);
        close(pipe1[1]);
        execlp("ls", "ls", "-l", NULL);
    }

    pipe(pipe2);
    pid2 = fork();

    if (pid2 == 0) {
        close(pipe1[1]);
        dup2(pipe1[0], 0);
        close(pipe1[0]);
        close(pipe2[0]);
        dup2(pipe2[1], 1);
        close(pipe2[1]);
        execlp("grep", "grep", "^p", NULL);
    }

    close(pipe1[0]);
    close(pipe1[1]);
    close(pipe2[1]);
    dup2(pipe2[0], 0);
    close(pipe2[0]);
    execlp("wc", "wc", NULL);

    return 0;
}
/* Output :
 * $ ./a.out
     10      90     605 
*/
