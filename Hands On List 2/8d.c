/*
 ============================================================================
 Name        : 8d.c
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
    printf("Caught SIGALRM: %d\n", signum);
    _exit(0);
}

int main() {
    signal(SIGALRM, handler);

    alarm(3); // send SIGALRM after 3 seconds
    printf("Alarm set for 3 seconds\n");

    while (1) pause();

    return 0;
}
/* Output : 
 * $ ./a.out
	Alarm set for 3 seconds
	Caught SIGALRM: 14
*/
