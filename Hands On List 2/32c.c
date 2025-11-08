/*
 ============================================================================
 Name        : 32c.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to implement semaphore to protect any critical section.
               a. rewrite the ticket number creation program using semaphore
               b. protect shared memory from concurrent write access
               c. protect multiple pseudo resources ( may be two) using counting semaphore
               d. remove the created semaphore
 Date        : 26 Sep, 2025
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int main() {
    key_t key = ftok(".", 'c');

    // create counting semaphore with initial value 2 (two resources)
    int sem_id = semget(key, 1, IPC_CREAT | 0666);
    union semun arg;
    arg.val = 2;
    semctl(sem_id, 0, SETVAL, arg);

    struct sembuf p = {0, -1, 0}, v = {0, 1, 0};

    printf("Press Enter to enter in Critical Section...\n");
    getchar();
    printf("Waiting..\n");

    semop(sem_id, &p, 1);  // acquire one resource
    printf("Process %d is using one resource\n", getpid());

    printf("Press Enter to exit from Critical Section...\n");
    getchar();

    printf("Process %d is exited from Critical Section.\n", getpid());
    semop(sem_id, &v, 1);  // release resource

    return 0;
}
/* Output :
 * $ ./a.out
	Press Enter to enter in Critical Section...
	
	Waiting..
	Process 5919 is using one resource
	Press Enter to exit from Critical Section...
	
	Process 5919 is exited from Critical Section.
  (Using three terminal, run ./a.out , it will allow only 2 process in Critical Section.)
*/ 
