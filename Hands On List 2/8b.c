/*
 ============================================================================
 Name        : 8b.c
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
    printf("Caught SIGINT: %d\n", signum);
    _exit(0);
}

int main() {
    signal(SIGINT, handler);

    while (1) {
        printf("Running... Press Ctrl+C to send SIGINT\n");
        sleep(1);
    }

    return 0;
}
/* Output :
 * $ ./a.out
   Running... Press Ctrl+C to send SIGINT
   Running... Press Ctrl+C to send SIGINT
   Running... Press Ctrl+C to send SIGINT
   ^CCaught SIGINT: 2
*/
