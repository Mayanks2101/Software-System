/*
 ============================================================================
 Name        : 13.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to wait for a STDIN for 10 seconds using select.
               Write a proper print statement to verify whether the data is available
               within 10 seconds or not (check in $man 2 select).
 Date        : 24 Aug, 2025
 ============================================================================
*/

// code :

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>

int main() {
    fd_set readfds;
    struct timeval timeout;
    int ret;

    FD_ZERO(&readfds);
    FD_SET(0, &readfds); // 0 is STDIN

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    printf("Waiting for input on STDIN for up to 10 seconds...\n");
    ret = select(1, &readfds, NULL, NULL, &timeout); //Readfds, writefds, exceptfds

    if (ret == -1) {
        perror("select");
        exit(1);
    } else if (ret == 0) {
        printf("Timeout: No input received within 10 seconds.\n");
    } else {
        if (FD_ISSET(0, &readfds)) {
            printf("Data is available on STDIN!\n");
        }
    }

    return 0;
}

/*
 Output:
 $ ./a.out
 Waiting for input on STDIN for up to 10 seconds...
 Hello
 Data is available on STDIN!
 $ Hello

*/
