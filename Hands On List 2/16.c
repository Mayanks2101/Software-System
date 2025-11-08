/*
 ============================================================================
 Name        : 16.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to send and receive data from parent to child vice versa. Use two way
               communication.
 Date        : 04 Sep, 2025
 ============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int fd1[2], fd2[2];
    char parent_msg[] = "Hello I am Parent";
    char child_msg[] = "Hi, I am Child";
    char buff[100];

    pipe(fd1);
    pipe(fd2);

    if (!fork()) {
        close(fd1[1]);
	close(fd2[0]);
	read(fd1[0], buff, sizeof(buff));
	printf("Child received message from parent : %s\n", buff);
	close(fd1[0]);

        write(fd2[1], child_msg, strlen(child_msg) + 1);
        close(fd2[1]);
    } 
    else {
        close(fd1[0]);
	close(fd2[1]);

        write(fd1[1], parent_msg, strlen(parent_msg)+1);
        printf("Parent Sent Message\n");
	close(fd1[1]);

	read(fd2[0], buff, sizeof(buff));
	printf("Parent Received message : %s\n", buff);
	close(fd2[0]);
    }

    return 0;
}
/* Output : 
 * $ ./a.out
 * Parent Sent Message
 * Child received message from parent : Hello I am Parent
 * Parent Received message : Hi, I am Child
*/
