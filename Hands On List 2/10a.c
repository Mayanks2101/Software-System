/*
 ============================================================================
 Name        : 10a.c
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
    printf("Caught SIGSEGV (signal number: %d)\n", signum);
    exit(1);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGSEGV, &sa, NULL);

    int *p = NULL;
    *p = 42; // trigger SIGSEGV

    return 0;
}
/* Output :
 * $ ./a.out
	Caught SIGSEGV (signal number: 11)
*/
