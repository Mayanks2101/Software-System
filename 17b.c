/*
 ============================================================================
 Name        : 17b.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to simulate online ticket reservation. Implement write lock.
               a. Write a program to open a file, store a ticket number and exit.
               b. Write a separate program to open the file, implement write lock,
               read the ticket number, increment the number and print the new ticket
               number then close the file.
 Date        : 27 Aug, 2025
 ============================================================================
*/

// code :

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main (){
	int fd;
	struct { int num; } ticket;
	struct flock lock;
	fd = open("17db", O_RDWR);
	read(fd, &ticket, sizeof(ticket));

	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();

	printf("Before entering to Critical section\n");
	fcntl(fd, F_SETLKW, &lock);
	printf("Inside the critical section\n");
	
	printf("Current Ticket Number : %d\n", ticket.num);
	ticket.num++;
	lseek(fd, 0L, SEEK_SET);

	printf("Press Enter to unlock..\n");
	write(fd, &ticket, sizeof(ticket));
	getchar();

	printf("DB File unlocking..\n");
	lock.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &lock);
	printf("DB File unlocked Successfully\n");

	printf("Ticket No : %d has been Updated\n", ticket.num);
	close(fd);	
}

/*
 Output:
 Terminal 1 : $ ./a.out
 Before entering to Critical section
 Inside the critical section
 Current Ticket Number : 20
 Press Enter to unlock..
 
 Terminal 2 : $ ./a.out
 Before entering to Critical section
 
 Terminal 1 : After pressing Enter
 DB File unlocking..
 DB File unlocked Successfully
 Ticket No : 21 has been Updated

 Terminal 2 : After pressing Enter in Terminal 1
 Inside the critical section
 Current Ticket Number : 21
 Press Enter to unlock..

 DB File unlocking..
 DB File unlocked Successfully
 Ticket No : 22 has been Updated
*/
