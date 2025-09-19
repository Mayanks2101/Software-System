/*
 ============================================================================
 Name        : 18a.c
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

	printf("Select Record Id :(1,2,3) :\n");
	scanf("%d", &input_id);
	
	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = (input_id-1)*sizeof(record);
	lock.l_len = sizeof(record);

	// Read Value
	printf("Before Entering into Critical Section..\n");
	fcntl(fd, F_SETLKW, &lock);
	lseek(fd, (input_id-1)*sizeof(record), SEEK_SET);
	read(fd, &record, sizeof(record));
	
	printf("Current Value is : %d\n", record.value);
	record.value++;

	lseek(fd, (-1)*sizeof(record), SEEK_CUR);
	write(fd, &record , sizeof(record));
	printf("Press Enter to update value..");
	getchar();
	getchar();
	
	lock.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &lock);

	close(fd);

	int fd_verify = open("18db.txt", O_RDONLY);

	lseek(fd_verify, (input_id - 1) * sizeof(record), SEEK_SET);

	struct { int id; int value; } updated_record;
	read(fd_verify, &updated_record, sizeof(updated_record));
	printf("Record No : %d has new Value : %d\n", input_id, updated_record.value);
	close(fd_verify);	
}

/*
 Output:

 SAME RECORD UPDATION EXAMPLE :-
  ==>(Terminal 1)
  $ ./a.out
   Select Record Id :(1,2,3) :
   1
   Before Entering into Critical Section..
   Current Value is : 0
   Press Enter to update value..
 
  ==>(Terminal 2)
  $ ./a.out
   Select Record Id :(1,2,3) :
   1
   Before Entering into Critical Section.. 
 
  ==>(Terminal 1)
   (After Pressing Enter..)
   Record No : 1 has new Value : 1
 
  ==>(Terminal 2)
   Current Value is : 1
   Press Enter to update value..
   Record No : 1 has new Value : 2

 DIFFERENT RECORD UPDATION EXAMPLE :-
  ==>(Terminal 1)
  $ ./a.out
   Select Record Id :(1,2,3) :
   3
   Before Entering into Critical Section..
   Current Value is : 1
   Press Enter to update value..

  ==>(Terminal 2)
  $ ./a.out
   Select Record Id :(1,2,3) :
   2
   Before Entering into Critical Section..
   Current Value is : 1
   Press Enter to update value..

  ==>(Terminal 1)
   Record No : 3 has new Value : 2 
 
  ==>(Terminal 2)
   Record No : 2 has new Value : 2

*/
