/*
 ============================================================================
 Name        : 3.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to create a file and print the file descriptor value.
               Use creat() system call.
 Date        : 16 Aug, 2025
 ============================================================================
*/

// code :

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	const char *filename = "3.txt";

	int fd = creat(filename, 0666);

        if (fd == -1) {
		perror("creat");
        	return 1;
    	}
	
    	printf("File '%s' created with file descriptor: %d\n", filename, fd);

    
    	close(fd);

   	return 0;
}

/*
 Output:
 $./a.out
 File '3.txt' created with file descriptor: 3

*/
