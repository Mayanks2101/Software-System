/*
 ============================================================================
 Name        : 10b.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a separate program using sigaction system call to catch the following signals.
               a. SIGSEGV
               b. SIGINT
               c. SIGFPE
 Date        : 25 Sep, 2025
 ============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void handler(int signum) {
    printf("Caught SIGINT (signal number: %d)\n", signum);
    exit(0);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, NULL);

    while (1) {
        printf("Running... Press Ctrl+C to trigger SIGINT\n");
        sleep(1);
    }

    return 0;
}
/* Output :
 * $ ./a.out
	Running... Press Ctrl+C to trigger SIGINT
	Running... Press Ctrl+C to trigger SIGINT
	^CCaught SIGINT (signal number: 2)
*/
