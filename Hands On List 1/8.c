/*
 ============================================================================
 Name        : 8.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to open a file in read only mode, read line by line
               and display each line as it is read. Close the file when end of file
               is reached.
 Date        : 17 Aug, 2025
 ============================================================================
*/

// code :

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
	    int fd = open("8.txt", O_RDONLY);
	    if (fd == -1) {
	        perror("open");
	        return 1;
	    }
	
	    char buffer[BUFFER_SIZE];
	    char line[BUFFER_SIZE];
	    int bytesRead, linePos = 0;
	
	    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
	        for (int i = 0; i < bytesRead; ++i) {
	            line[linePos++] = buffer[i];
	            if (buffer[i] == '\n') {
	                write(STDOUT_FILENO, line, linePos);
	                linePos = 0;
	            	sleep(1);
		    }
	        }
	    }
	
	    if (linePos > 0) {
	        write(STDOUT_FILENO, line, linePos);
	    }
	
	    close(fd);
	    return 0;
}

/*
 Output:
 $./a.out
 This is line one.
 Here is line two.
 Now comes line three.
 Almost done with line four.
 Finally, this is line five.


*/
