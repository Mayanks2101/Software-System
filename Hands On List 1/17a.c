/*
 ============================================================================
 Name        : 17a.c
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
	printf("Enter Ticket Number to Store :");
	scanf("%d",&ticket.num);
	fd = open("17db", O_RDWR);
	write(fd, &ticket, sizeof(ticket));
	close(fd);
	fd = open("17db", O_RDONLY);
	read(fd, &ticket, sizeof(ticket));
	printf("Ticket No : %d has been stored\n", ticket.num);
	close(fd);	
}

/*
 Output:
 $ ./a.out
 Enter Ticket Number to Store :20
 Ticket No : 20 has been stored
*/
