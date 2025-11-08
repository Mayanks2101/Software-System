/*
 ============================================================================
 Name        : 32d.c
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
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main() {
    key_t key = ftok(".", 'a');
    int semid = semget(key, 1, IPC_CREAT | 0666);

    if (semid == -1) {
        perror("semget failed");
        return 1;
    }

    printf("Semaphore ID = %d\n", semid);
    printf("Semaphore created, check with: ipcs -s\n");
    printf("Semaphore will removed after 10sec...\n");
    sleep(10);

    semctl(semid, 0, IPC_RMID);
    printf("Semaphore removed.\n");

    return 0;
}

/* Output :
 * $ ./a.out
	Semaphore ID = 0
	Semaphore created, check with: ipcs -s
	Semaphore will removed after 10sec...
	Semaphore removed.

 * (In Other Terminal to Verify Semaphore status)
 * $ ipcs -s
	
	------ Semaphore Arrays --------
	key        semid      owner      perms      nsems     
	0x61050109 0          mayank     666        1         
	
	mayank@mayank-IdeaPad-5-15ITL05:~/Mayank/SEM1/SS/lab$ ipcs -s
	
	------ Semaphore Arrays --------
	key        semid      owner      perms      nsems     

*/
