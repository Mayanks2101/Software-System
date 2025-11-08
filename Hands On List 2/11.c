/*
 ============================================================================
 Name        : 11.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
               use sigaction system call.
 Date        : 26 Sep, 2025
 ============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    struct sigaction sa_ignore, sa_default;

    // Ignore SIGINT
    sa_ignore.sa_handler = SIG_IGN;
    sigemptyset(&sa_ignore.sa_mask);
    sa_ignore.sa_flags = 0;
    sigaction(SIGINT, &sa_ignore, NULL);

    printf("SIGINT (Ctrl+C) is ignored for 5 seconds.\n");
    sleep(5);

    // Reset SIGINT to default action
    sa_default.sa_handler = SIG_DFL;
    sigemptyset(&sa_default.sa_mask);
    sa_default.sa_flags = 0;
    sigaction(SIGINT, &sa_default, NULL);

    printf("\nSIGINT reset to default action. Press Ctrl+C to terminate.\n");

    while (1) {
        sleep(1);
    }

    return 0;
}
/* Output : 
 * $ ./a.out
	SIGINT (Ctrl+C) is ignored for 5 seconds.
	^C^C^C
	SIGINT reset to default action. Press Ctrl+C to terminate.
	^C
*/
