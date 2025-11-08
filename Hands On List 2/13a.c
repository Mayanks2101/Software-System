/*
 ============================================================================
 Name        : 13a.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
               will send the signal (using kill system call). Find out whether the first program is able to catch
               the signal or not.
 Date        : 28 Sep, 2025
 ============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum) {
    printf("Caught signal: %d\n", signum);
}

int main() {
    signal(SIGSTOP, handler); // Attempt to catch SIGSTOP

    printf("PID: %d. Waiting for SIGSTOP...\n", getpid());

    while (1) {
        pause(); // Wait for signals
    }

    return 0;
}
/* Output : 
 * $ cc 13a.c
 * $ ./a.out
	PID: 11024. Waiting for SIGSTOP...
(After Receiving SIGSTOP from 13b.c)	
	[1]+  Stopped                 ./a.out
*/
