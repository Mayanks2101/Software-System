/*
 ============================================================================
 Name        : 8e.c
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
#include <sys/time.h>

void handler(int signum) {
    printf("Caught SIGALRM (setitimer): %d\n", signum);
    _exit(0);
}

int main() {
    signal(SIGALRM, handler);

    struct itimerval timer;
    timer.it_value.tv_sec = 4;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);

    printf("setitimer set for 4 seconds\n");

    while (1) pause();

    return 0;
}

/* Output : 
 * $ ./a.out
	setitimer set for 4 seconds
	Caught SIGALRM (setitimer): 14
*/
