/*
 ============================================================================
 Name        : 25.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to create three child processes. The parent should wait
               for a particular child (use waitpid system call).
 Date        : 31 Aug, 2025
 ============================================================================
*/

// code :

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	pid_t child1, child2, child3;
	child1 = fork();
    	if (child1 == 0) {
        	printf("Child 1 PID: %d\n", getpid());
        	sleep(2);
        	exit(1);
   	 }

   	 child2 = fork();
   	 if (child2 == 0) {
   	     	printf("Child 2 PID: %d\n", getpid());
         	sleep(4);
   	 	exit(2);
   	 }
	
	 child3 = fork();
	 if (child3 == 0) {
         	printf("Child 3 PID: %d\n", getpid());
        	sleep(6);
        	exit(3);
    	}
	
	int status;
    	waitpid(child2, &status, 0);
    	perror("Child 2 exited with status: ");
    	

    	wait(NULL);
    	wait(NULL);
    	return 0;
}

/*
 Output:
 $ ./a.out
  Child 1 PID: 14016
  Child 2 PID: 14017
  Child 3 PID: 14018
  Child 2 exited with status: : Success

*/
