/*
 ============================================================================
 Name        : 26.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to send messages to the message queue. Check $ipcs -q
 Date        : 14 Sep, 2025
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_TEXTSIZE 512

int main() {
    key_t key = ftok(".", 65);
    int msqid = msgget(key, IPC_CREAT | 0666);
    
    struct msgstruct {
    	long mtype;
    	char mtext[MAX_TEXTSIZE];
    };
    struct msgstruct message;

    message.mtype = 1;
    printf("Enter Message : ");
    if(fgets(message.mtext, MAX_TEXTSIZE, stdin)== NULL){
	perror("fgets : ");
    }

    if(msgsnd(msqid, &message, strlen(message.mtext) + 1, 0) == -1){
	perror("msgsnd : ");
	return 0;
    }
    printf("Message sent successfully : %s\n", message.mtext);

    //msgctl(msqid, IPC_RMID, NULL);

    return 0;
}

/* Output : 
 * $ ./a.out
	Enter Message : Hello
	Message sent successfully : Hello
 * 
 * $ ipcs -q
   ------ Message Queues --------
   key        msqid      owner      perms      used-bytes   messages    
   0x41050109 3          mayank     666        7            1  
 * 
 * $ ./a.out
	Enter Message : How Are You?
	Message sent successfully : How Are You?
 * 
 * $ ipcs -q
   ------ Message Queues --------
   key        msqid      owner      perms      used-bytes   messages    
   0x41050109 3          mayank     666        21           2           
*/

