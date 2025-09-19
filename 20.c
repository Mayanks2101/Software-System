/*
 ============================================================================
 Name        : 20.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Find out the priority of your running program. Modify the priority with nice command.
 Date        : 30 Aug, 2025
 ============================================================================
*/

// code :

#include<unistd.h>
#include<stdio.h>
#include<sys/resource.h>

int main(){
	printf("The Priority of current process is  : %d\n", getpriority(PRIO_PROCESS, 0));
	nice(-4);
	perror("nice operation:");

	setpriority(PRIO_PROCESS, 0, 5);
	printf("The modified priority is : %d\n", getpriority(PRIO_PROCESS, 0));
}

/*
 Output:
 $ sudo ./a.out
 The Priority of current process is  : 0
 nice operation:: Success
 The modified priority is : 5 
*/
