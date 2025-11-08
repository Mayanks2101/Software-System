/*
 ============================================================================
 Name        : 17.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to execute ls -l | wc.
               a. use dup
               b. use dup2
               c. use fcntl
 Date        : 05 Sep, 2025
 ============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
    int fd[2];
    pid_t pid;
    int choice;

    printf("Choose method for redirection:\n");
    printf("1. dup\n");
    printf("2. dup2\n");
    printf("3. fcntl\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    pipe(fd);
    pid = fork();

    if (pid == 0) {
        //For wc
 	close(fd[1]);// close write end

        switch (choice) {
            case 1:
                close(0);
                dup(fd[0]);
                break;

            case 2:
                dup2(fd[0], 0);
                break;

            case 3:
                close(0);
		fcntl(fd[0], F_DUPFD, 0);
                break;

            default:
                fprintf(stderr, "Invalid choice\n");
                exit(1);
        }

        close(fd[0]);
        execlp("wc", "wc", NULL);
    }
    else {
        // For ls -l
        close(fd[0]);  // close read end

        switch (choice) {
            case 1:
                close(1);
                dup(fd[1]);
                break;

            case 2:
                dup2(fd[1], 1);
                break;

            case 3:
		close(1);
                fcntl(fd[1], F_DUPFD, 1);
                break;
        }

        close(fd[1]);
        execlp("ls", "ls", "-l", NULL);
    }

    return 0;
}

/* Output : 
 * $ ./a.out
 * Choose method for redirection:
 * 1. dup
 * 2. dup2
 * 3. fcntl
 * Enter choice: 1
 *     7      56     325
 * 
 * $ ./a.out
 * Choose method for redirection:
 * 1. dup
 * 2. dup2
 * 3. fcntl
 * Enter choice: 2
      7      56     325
 * 
 * $ ./a.out
 * Choose method for redirection:
 * 1. dup
 * 2. dup2
 * 3. fcntl
 * Enter choice: 3
      7      56     325
*/ 


