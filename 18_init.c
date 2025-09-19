/*
 ============================================================================
 Name        : 18.c (Initialize record data in database)
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

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

struct { int id; int value; } record;

int main() {
    int fd = open("18db.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    for (int i = 1; i <= 3; i++) {
        record.id = i;
        record.value = 0;
        write(fd, &record, sizeof(record));
    }
    close(fd);
    return 0;
}

/* Output :
  It will initialize 3 records with default value 0 in 18db.txt
*/
