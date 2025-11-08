/*
 ============================================================================
 Name        : 10c.c
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

void handler(int signum) {
    printf("Caught SIGFPE (signal number: %d)\n", signum);
    exit(1);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGFPE, &sa, NULL);

    int x = 1 / 0; // trigger SIGFPE

    return 0;
}
/* Output : 
 * $ ./a.out
	Caught SIGFPE (signal number: 8)
*/
