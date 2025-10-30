/*
 ============================================================================
 Name        : 26.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to execute an executable program.
               a. use some executable program
               b. pass some input to an executable program. (for example execute an
                  executable of $./a.out name)
 Date        : 3 Sept, 2025
 ============================================================================
*/

// code :

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    pid_t pid = fork();

    if (pid == 0) {
        execl("./26name", argv[1], argv[2], NULL);
        perror("execl failed");
        exit(1);
    } else if (pid > 0) {
        wait(NULL);
        printf("Child process completed.\n");
    } else {
        perror("fork failed");
        exit(1);
    }

    return 0;
}

/*
 Output:
 $ ./a.out Mayank CSE
  First parameter is Mayank
  Second parameter is CSE
  Child process completed.
*/
