/*
 ============================================================================
 Name        : 16a.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to perform mandatory locking.
               a. Implement write lock
               b. Implement read lock
 Date        : 27 Aug, 2025
 ============================================================================
*/

// code :

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main (int argc, char* argv[]){
	struct flock lock;
	int fd;
	fd = open("16a.txt", O_RDWR);
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();
	
	printf("Before entering to Critical section\n");
	fcntl(fd, F_SETLKW, &lock);
	printf("Inside the critical section\n");
	printf("Press Enter to unlock..\n");
	getchar();
	printf("File unlocking..\n");
	lock.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &lock);
	printf("File unlocked Successfully\n");
}

/*
 Output:
 $ ./a.out
 Before entering to Critical section
 Inside the critical section
 Press Enter to unlock..

 (Other Terminal)
 $ ./a.out
 Before entering to Critical section

*/
