/*
 ============================================================================
 Name        : 25.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
               a. access permission
               b. uid, gid
               c. time of last message sent and received
               d. time of last change in the message queue
               e. size of the queue
               f. number of messages in the queue
               g. maximum number of bytes allowed
               h. pid of the msgsnd and msgrcv
 Date        : 13 Sep, 2025
 ============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>

int main() {
    key_t key = ftok("msgqueue", 65);
    int msqid = msgget(key, 0666 | IPC_CREAT);

    struct msqid_ds msg_info;
    msgctl(msqid, IPC_STAT, &msg_info);

    printf("Access Permissions: %o\n", msg_info.msg_perm.mode & 0777);
    printf("UID: %d\n", msg_info.msg_perm.uid);
    printf("GID: %d\n", msg_info.msg_perm.gid);
    printf("Time of Last Message Sent: %s", ctime(&msg_info.msg_stime));
    printf("Time of Last Message Received: %s", ctime(&msg_info.msg_rtime));
    printf("Time of Last Change: %s", ctime(&msg_info.msg_ctime));
    printf("Current Size of the Queue (in bytes): %lu\n", msg_info.__msg_cbytes);
    printf("Number of Messages in the Queue: %lu\n", msg_info.msg_qnum);
    printf("Maximum Bytes Allowed: %lu\n", msg_info.msg_qbytes);
    printf("PID of Last msgsnd: %d\n", msg_info.msg_lspid);
    printf("PID of Last msgrcv: %d\n", msg_info.msg_lrpid);

    return 0;
}

/* Output : 
 * $ ./a.out
 	Access Permissions: 666
 	UID: 1000
 	GID: 1000
 	Time of Last Message Sent: Thu Jan  1 05:30:00 1970
 	Time of Last Message Received: Thu Jan  1 05:30:00 1970
 	Time of Last Change: Sun Sep 21 17:17:00 2025
 	Current Size of the Queue (in bytes): 0
 	Number of Messages in the Queue: 0
 	Maximum Bytes Allowed: 16384
 	PID of Last msgsnd: 0
 	PID of Last msgrcv: 0
*/
