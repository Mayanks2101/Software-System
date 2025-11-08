/*
 ============================================================================
 Name        : 32a.c
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
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>

struct ticket {
    char train_name[20];
    int ticket_num;
};

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int main() {
    key_t key = ftok(".", 'a');
    int sem_id = semget(key, 1, IPC_CREAT | 0666);
    
    int fd = open("32ticket_db.txt", O_RDWR | O_CREAT, 0744);
    
    union semun arg;
    arg.val = 1; 
    semctl(sem_id, 0, SETVAL, arg);

    struct sembuf p = {0, -1, 0}, v = {0, 1, 0};
    //sembuf{short sem_num, short sem_op, short sem_flg}

    struct ticket t;
    printf("Press Enter to start booking...");
    getchar();
    semop(sem_id, &p, 1);   // lock
    
    printf("You are in Critical Section..\n");

    if (read(fd, &t, sizeof(t)) <= 0) {
	printf("Last ticket Number is %d\n", t.ticket_num);
        strcpy(t.train_name, "Train1");
        t.ticket_num = 1;
    } 
    else {
	printf("Last ticket Number is %d\n", t.ticket_num);
        t.ticket_num++;
    
    }
    printf("Press Enter to finish booking...\n");
    getchar(); 
    lseek(fd, 0, SEEK_SET);
    write(fd, &t, sizeof(t));

    printf("Train Ticket booked with below details :\n");
    printf("Train: %s \nTicket: %d\n", t.train_name, t.ticket_num);
    
    close(fd);
    semop(sem_id, &v, 1);   // unlock
    sleep(1);
    
    return 0;
}
/* Output :
 * $ ./a.out
	Press Enter to start booking...
	You are in Critical Section..
	Last ticket Number is 3
	Press Enter to finish booking...

	Train Ticket booked with below details :
	Train: Train1 
	Ticket: 4
*/
