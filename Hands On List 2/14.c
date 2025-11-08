/*
 ============================================================================
 Name        : 14.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on
               the monitor.
 Date        : 02 Sep, 2025
 ============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    char write_msg[] = "Hello using Pipe";
    char read_msg[100];

    pipe(fd);
    printf("Message Sent from Pipe is : %s\n", write_msg);
    write(fd[1], write_msg, strlen(write_msg)+1); // +1 for \0
    read(fd[0], read_msg, sizeof(read_msg));
    printf("Message Read from pipe is : %s\n", read_msg);	

    return 0;
}

/* Output : 
 * $./a.out
 * Message Sent from Pipe is : Hello using Pipe
 * Message Read from pipe is : Hello using Pipe
 *
 *
*/
