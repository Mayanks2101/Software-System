/*
 ============================================================================
 Name        : 21a.c
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

    fd_write = open("21fifo1", O_WRONLY);
    fd_read = open("21fifo2", O_RDONLY);

    while(1){
    	printf("Enter message to send to B: ");
    	fgets(message, sizeof(message), stdin);
    	write(fd_write, message, strlen(message) + 1);

    	read(fd_read, buffer, sizeof(buffer));
    	printf("Received message from B: %s\n", buffer);
    }
    close(fd_write);
    close(fd_read);
    return 0;
}
/* Output : 
 * $ mkfifo 21fifo1
 * $ mkfifo 21fifo2
 * $ ./a.out
	Enter message to send to B: Hello I am Alice
	Received message from B: Hello I am Bob

	Enter message to send to B: How are you Bob?
	Received message from B: I am Fine Alice.
 *
*/
