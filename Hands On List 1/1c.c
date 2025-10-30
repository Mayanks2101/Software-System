/*
 ============================================================================
 Name : 1c.c
 Author : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : 1. Create the following types of a files using (ii) system call
                       c. FIFO (using mknod system call)
 Date: 15 Aug, 2025.
 ============================================================================
*/

//code :
   

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
	if (mkfifo("fifo_file_syscall", 0666) == -1) {
        	perror("mkfifo");
        	return 1;
    	}
	else{
		printf("FIFO file named \"fifo_file_syscall\" created Successfully using system call\n");
	}
	return 0;
}

/*
 Output :

 ./a.out
 ls | grep 'fifo_file_syscall'
 fifo_file_syscall
*/

