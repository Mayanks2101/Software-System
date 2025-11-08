/*
 ============================================================================
 Name        : 1b.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a separate program (for each time domain) to set a interval timer in 10sec and 10micro second
               a. ITIMER_REAL
               b. ITIMER_VIRTUAL
               c. ITIMER_PROF
 Date        : 16 Sep, 2025
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int sig) {
    printf("ITIMER_VIRTUAL expired!\n");
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
    ITIMER_VIRTUAL expired!
 *
*/ 
