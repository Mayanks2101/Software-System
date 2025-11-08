/*
 ============================================================================
 Name        : 24.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to create a message queue and print the key and message queue id.
 Date        : 12 Sep, 2025
 ============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key;
    int msgid;

    key = ftok(".", 'a');
    msgid = msgget(key, IPC_CREAT | 0666);

    printf("Key = %d\n", key);
    printf("Message Queue ID = %d\n", msgid);

    return 0;
}
/* Output :
 * $ ./a.out
	Key = 1627717897
	Message Queue ID = 0
 * $ ipcs -q	
	------ Message Queues --------
	key        msqid      owner      perms      used-bytes   messages    
	0x61050109 0          mayank     666        0            0 
*/
