/*
 ============================================================================
 Name        : 12.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
               the parent process from the child process.
 Date        : 27 Sep, 2025
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {  
        // Child process
        printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());

        sleep(2); // Give parent time to run

        printf("Child sending SIGKILL to parent (PID = %d)\n", getppid());
        kill(getppid(), SIGKILL); // Kill parent

        printf("Child continuing after killing parent...\n");

        sleep(5); //child continues
        printf("Child process: PID = %d, New Parent PID = %d \n", getpid(), getppid());
    } 
    else {
        // Parent process
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
        while (1) {
            printf("Parent running...\n");
            sleep(1);
        }
    }

    return 0;
}
/* Output :
 * $ ./a.out
	Parent process: PID = 10851, Child PID = 10852
	Parent running...
	Child process: PID = 10852, Parent PID = 10851
	Parent running...
	Child sending SIGKILL to parent (PID = 10851)
	Child continuing after killing parent...
	Killed
	$ Child process: PID = 10852, New Parent PID = 2030 
*/
