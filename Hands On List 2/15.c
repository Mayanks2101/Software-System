/*
 ============================================================================
 Name        : 15.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a simple program to send some data from parent to the child process.
 Date        : 03 Sep, 2025
 ============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    char write_msg[] = "Hello from Parent Process";
    char read_msg[100];

    pipe(fd);

    if(!fork()){
	close(fd[1]);
	read(fd[0], read_msg, sizeof(read_msg));
        printf("Child Process received : %s\n", read_msg);	
	close(fd[0]);
    }
    else{
	close(fd[0]);
	write(fd[1], write_msg, strlen(write_msg) + 1);
	printf("Parent Process sent msg : %s\n", write_msg);
    	close(fd[1]);
    }

    return 0;
}
/* Output : 
 * $ ./a.out
 * Parent Process sent msg : Hello from Parent Process
 * Child Process received : Hello from Parent Process
*/


