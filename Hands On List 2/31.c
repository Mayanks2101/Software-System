/*
 ============================================================================
 Name        : 31.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to create a semaphore and initialize value to the semaphore.
               a. create a binary semaphore
               b. create a counting semaphore
 Date        : 25 Sep, 2025
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>

union semun {
    int val;                // value for SETVAL
    struct semid_ds *buf;   // buffer for IPC_STAT, IPC_SET
    unsigned short *array;  // array for GETALL, SETALL
};

int main() {
    key_t key;
    int semid;
    union semun arg;

    key = ftok(".", 'b');

    // ==> Create Binary Semaphore ---------
    semid = semget(key, 1, IPC_CREAT | 0744);
    arg.val = 1;  
    if (semctl(semid, 0, SETVAL, arg) == -1) {
        perror("semctl");
        exit(1);
    }
    printf("Binary Semaphore created (id=%d) and initialized to 1.\n", semid);

    // ==> Create Counting Semaphore ---------
    key = ftok(".", 'c');
    semid = semget(key, 1, IPC_CREAT | 0744);
    if (semid == -1) {
        perror("semget");
        exit(1);
    }
    arg.val = 5;
    if (semctl(semid, 0, SETVAL, arg) == -1) {
        perror("semctl");
        exit(1);
    }
    printf("Counting Semaphore created (id=%d) and initialized to 5.\n", semid);

    return 0;
}
/* Output :
 * $ ./a.out
	Binary Semaphore created (id=0) and initialized to 1.
	Counting Semaphore created (id=1) and initialized to 5.
 * $ ipcs -s	
	------ Semaphore Arrays --------
	key        semid      owner      perms      nsems     
	0x62050109 0          mayank     744        1         
	0x63050109 1          mayank     744        1     
*/
