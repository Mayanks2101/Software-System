/*
 ============================================================================
 Name        : 4.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to open an existing file with read write mode.
               Try O_EXCL flag also.
 Date        : 16 Aug, 2025
 ============================================================================
*/

// code :

#include <stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>

int main() {
	const char *filename = "4.txt";

	int fd = open(filename, O_RDWR);

        if (fd == -1) {
		perror("Filed to open file\n");
        	return 1;
    	}
	else{
		printf("File opened with fd value %d \n", fd);
	}

	printf("Now Trying to Open this existing file with O_EXCL\n");

	fd = open(filename, O_RDWR | O_CREAT | O_EXCL);
	if(fd == -1){
		if(errno == EEXIST){
			printf("File Already Exists. So failed to open() due to O_EXCL\n");
		}
		else {
			perror("open() failed unexpectedly\n");
		}
	}
	else {
		printf("File opened with O_EXCL : Unexpectable\n");
		close(fd);
	}
	return 0;
}

/*
 Output:
 $./a.out
 File opened with fd value 3 
 Now Trying to Open this existing file with O_EXCL
 File Already Exists. So failed to open() due to O_EXC
*/
