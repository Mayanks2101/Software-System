/*
 ============================================================================
 Name        : 6.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to take input from STDIN and display on STDOUT.
               Use only read/write system calls.
 Date        : 17 Aug, 2025
 ============================================================================
*/

// code:

#include <unistd.h>
#include <fcntl.h>

int main() {
	char buffer[1024];
	ssize_t bytesRead;

	while ((bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0) {

        	write(STDOUT_FILENO, buffer, bytesRead);
    	}

  	return 0;
}

/*
 Output:
 $./a.out
 Hello I am Linux (Press Enter)
 Hello I am Linux

*/
