/*
 ============================================================================
 Name        : 22.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select
               system call with FIFO.
 Date        : 10 Sep, 2025
 ============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/stat.h>

int main() {
    int fd;
    char buffer[100];
    fd_set readfds;
    struct timeval tv;
    int ret;

    mkfifo("22fifo", 0666);
    fd = open("22fifo", O_RDONLY | O_NONBLOCK);

    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);

    tv.tv_sec = 10;
    tv.tv_usec = 0;

    printf("Waiting for data in FIFO (10 seconds)...\n");

    ret = select(fd + 1, &readfds, NULL, NULL, &tv);

    if(ret == -1){
	    perror("Select");
    }
    else if (ret==0){
	    printf("Timeout! No data received within 10seconds\n");
    }
    else{

	    if(read(fd, buffer, sizeof(buffer)-1) > 0){
		    //:buf[n] = '\0';
    	    	    printf("Received data is : %s\n", buffer);
	    }
	    else{
		    printf("FIFO opened but no data written.\n");
	    }
    }

    close(fd);
    return 0;
}
/* Output :
 * ==> TERMINAL 1
 * $ ./a.out
	Waiting for data in FIFO (10 seconds)...
	Received data is : Hello I am Mayank
 * 
 * ==> TERMINAL 2 (For sending Message in 10sec)
 * $ echo "Hello I am Mayank" > 22fifo
*/
