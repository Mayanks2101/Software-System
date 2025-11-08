/*
 ============================================================================
 Name        : 20sender.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write two programs so that both can communicate by FIFO - Use one way communication.
 Date        : 08 Sep, 2025
 ============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd;
    char message[100];

    fd = open("20fifo", O_WRONLY);

    printf("Enter message to send: ");
    fgets(message, sizeof(message), stdin);

    write(fd, message, strlen(message) + 1);
    close(fd);

    return 0;
}
/* Output : 
 * $ mkfifo 20fifo
 * $ ./a.out
 *  Enter message to send: I am Mayank
*/
