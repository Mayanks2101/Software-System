/*
 ============================================================================
 Name        : 8c.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a separate program using signal system call to catch the following signals.
               a. SIGSEGV
               b. SIGINT
               c. SIGFPE
               d. SIGALRM (use alarm system call)
               e. SIGALRM (use setitimer system call)
               f. SIGVTALRM (use setitimer system call)
               g. SIGPROF (use setitimer system call)
 Date        : 23 Sep, 2025
 ============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum) {
    printf("Caught SIGFPE: %d\n", signum);
    _exit(1);
}

int main() {
    signal(SIGFPE, handler);

    int x = 1 / 0; // triggers floating point exception

    return 0;
}
/* Output :
 * $ ./a.out
	Caught SIGFPE: 8
*/
