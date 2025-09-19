/*
 ============================================================================
 Name        : 18b.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to perform Record locking.
		a. Implement write lock
		b. Implement read lock
	       Create three records in a file. Whenever you access a particular
	       record, first lock it then modify/access to avoid race condition. 
 Date        : 28 Aug, 2025
 ============================================================================
*/

// code :

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

struct { int id; int value; } record;

int main (){
	int fd = open("18db.txt", O_RDWR);
	int input_id;
	int value;

	printf("Select Record Id to Read :(1,2,3) :\n");
	scanf("%d", &input_id);
	
	struct flock lock;
	lock.l_type = F_RDLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = (input_id-1)*sizeof(record);
	lock.l_len = sizeof(record);

	// Read Value
	printf("Before Entering into Critical Section..\n");
	fcntl(fd, F_SETLKW, &lock);
	lseek(fd, (input_id-1)*sizeof(record), SEEK_SET);
	read(fd, &record, sizeof(record));
	
	printf("Current Value of Record %d is : %d\n", input_id, record.value);	
	printf("Press Enter to Finish..");
	getchar();
	getchar();
	
	lock.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &lock);
	printf("File unlocked Successfully");
	close(fd);	
  
}

/*
 Output:

 SAME RECORD READ EXAMPLE :-
  ==>(Terminal 1)
  $./a.out
   Select Record Id to Read :(1,2,3) :
   2
   Before Entering into Critical Section..
   Current Value of Record 2 is : 2
   Press Enter to Finish..

  ==>(Terminal 2)
  $ ./a.out
   Select Record Id to Read :(1,2,3) :
   2
   Before Entering into Critical Section..
   Current Value of Record 2 is : 2
   Press Enter to Finish..


*/
