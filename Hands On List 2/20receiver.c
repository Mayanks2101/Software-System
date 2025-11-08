/*
 ============================================================================
 Name        : 20receiver.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write two programs so that both can communicate by FIFO - Use one way communication.
 Date        : 08 Sep, 2025
 ============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[100];

    fd = open("20fifo", O_RDONLY);

    read(fd, buffer, sizeof(buffer));
    printf("Received message: %s\n", buffer);

    close(fd);
    return 0;
}
/* Output :
 * $ cc 20receiver.c -o aa.out
 * $ ./aa.out
 * Received message: I am Mayank
*/
