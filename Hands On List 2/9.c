/*
 ============================================================================
 Name        : 9.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
               signal - Use signal system call.
 Date        : 24 Sep, 2025
 ============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum) {
    printf("SIGINT received but ignored!\n");
}

int main() {
    printf("Press Ctrl+C. SIGINT will be ignored for 5 seconds.\n");

    signal(SIGINT, SIG_IGN);
    sleep(5);

    printf("\nNow resetting SIGINT to default action.\n");
    signal(SIGINT, SIG_DFL);

    printf("Press Ctrl+C again to terminate the program.\n");

    while (1) {
        sleep(1);
    }

    return 0;
}
/* Output :
 * $ ./a.out
   Press Ctrl+C. SIGINT will be ignored for 5 seconds.
   ^C^C^C
   Now resetting SIGINT to default action.
   Press Ctrl+C again to terminate the program.
   ^C
*/ 
