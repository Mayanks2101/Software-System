/*
 ============================================================================
 Name        : 21b.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write two programs so that both can communicate by FIFO - Use two way communications.
 Date        : 09 Sep, 2025
 ============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd_write, fd_read;
    char message[100], buffer[100];

    fd_read = open("21fifo1", O_RDONLY);
    fd_write = open("21fifo2", O_WRONLY);
    
    while(1){
    	read(fd_read, buffer, sizeof(buffer));
    	printf("Received message from A: %s\n", buffer);

    	printf("Enter message to send to A: ");
    	fgets(message, sizeof(message), stdin);
    	write(fd_write, message, strlen(message) + 1);
    }
    close(fd_write);
    close(fd_read);
    return 0;
}

/* Output : 
 * $ cc 21b.c -o aa.out 
 * $ ./aa.out
	Received message from A: Hello I am Alice

	Enter message to send to A: Hello I am Bob
	Received message from A: How are you Bob?
	
	Enter message to send to A: I am Fine Alice.
	Received message from A: How are you Bob?
*/
