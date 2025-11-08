/*
 ============================================================================
 Name        : 30.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to create a shared memory.
               a. write some data to the shared memory
               b. attach with O_RDONLY and check whether you are able to overwrite.
               c. detach the shared memory
               d. remove the shared memory
 Date        : 24 Sep, 2025
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <signal.h>
#define SHM_SIZE 1024

int shmid;
char *data;
void handler(int sig){
	printf("Caught SIGSEGV : Cannot write in READ-ONLY shared Memory.\n");
	shmdt(data);
        printf("Memory Detached Successfully.\n");

        shmctl(shmid, IPC_RMID, NULL);
        printf("Shared memory removed.\n");
	exit(1);

}

int main() {
    key_t key;
    //int shmid;
    //char *data;

    key = ftok(".", 'a');
    signal(SIGSEGV, handler);

    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    printf("Shared memory created with id: %d\n", shmid);

    // Attach to shared memory (read/write)
    data = shmat(shmid, NULL, 0);
    if (data == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    // Write data
    strcpy(data, "This line is written in shared memory");
    printf("Data in shared memory written is : %s\n", data);

    // Detach after writing
    if (shmdt(data) == -1) {
        perror("shmdt");
        exit(1);
    }
    printf("Shared Memory Detached Successfully.\n\n");

    // Attach again with READ ONLY
    data = shmat(shmid, NULL, SHM_RDONLY);
    if (data == (char *)-1) {
        perror("shmat (SHM_RDONLY)");
        exit(1);
    }
    printf("Shared Memory attached aggain with Read Only Mode.\n");
    printf("Reading from shared memory : %s\n", data);

    // Trying to overwrite
    printf("Trying to overwrite in READ-ONLY mode...\n");
    strcpy(data, "New Data");  

    // Detach after read-only
    if (shmdt(data) == -1) {
        perror("shmdt");
        exit(1);
    }
    printf("Detached after read-only access.\n");

    // Remove shared memory
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }
    printf("Shared memory removed.\n");

    return 0;
}
/* Output : 
 * $ ./a.out
	Shared memory created with id: 65582
	Data in shared memory written is : This line is written in shared memory
	Shared Memory Detached Successfully.
	
	Shared Memory attached aggain with Read Only Mode.
	Reading from shared memory : This line is written in shared memory
	Trying to overwrite in READ-ONLY mode...
	Caught SIGSEGV : Cannot write in READ-ONLY shared Memory.
	Memory Detached Successfully.
	Shared memory removed.
*/
