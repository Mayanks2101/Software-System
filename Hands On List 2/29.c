/*
 ============================================================================
 Name        : 29.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to remove the message queue.
 Date        : 17 Sep, 2025
 ============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

int main() {
    key_t key = ftok(".", 65);
    int msqid = msgget(key, IPC_CREAT | 0666);	
    if(msqid == -1){
	   perror("msqid : ");
	   return 1;
    }
    printf("Message queue id (%d) generated. You can verify with ipcs -q in 10 sec\n", msqid);
    sleep(10);
    msgctl(msqid, IPC_RMID, NULL);
    printf("Message queue id (%d) removed.\n",msqid);

    return 0;
}
/* Output : 
 * $ ./a.out
   Message queue id (6) generated. You can verify with ipcs -q in 10 sec
   Message queue id (6) removed.

 * (Another Terminal for verification )
 * $ ipcs -q
  ------ Message Queues --------
  key        msqid      owner      perms      used-bytes   messages
  0x41050109 6          mayank     666        0            0

 * $ ipcs -q
  ------ Message Queues --------
  key        msqid      owner      perms      used-bytes   messages
*/
