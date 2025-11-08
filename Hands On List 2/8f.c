/*
 ============================================================================
 Name        : 8f.c
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
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int signum) {
    printf("Caught SIGVTALRM : %d\n", signum);
}

int main() {
    struct itimerval timer;
    signal(SIGVTALRM, handler);

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    while (1) { }   // consumes CPU (virtual time runs only when process runs)
}
/* Output :
 * $ ./a.out
    Caught SIGVTALRM : 26
 *
*/ 
