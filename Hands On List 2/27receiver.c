/*
 ============================================================================
 Name        : 27receiver.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to receive messages from the message queue.
               a. with 0 as a flag
               b. with IPC_NOWAIT as a flag
 Date        : 15 Sep, 2025
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

#define MAX 100

struct msgbuf {
    long mtype;
    char mtext[MAX];
};

int main() {
    key_t key;
    int msgid, choice;
    struct msgbuf message;

    key = ftok(".", 'b');
    msgid = msgget(key, IPC_CREAT | 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    printf("1. Blocking Receive\n");
    printf("2. Non-Blocking Receive\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            if (msgrcv(msgid, &message, sizeof(message.mtext), 1, 0) == -1) {
                perror("msgrcv");
            } 
	    else {
                printf("Received (blocking): %s\n", message.mtext);
            }
            break;

        case 2:
            if (msgrcv(msgid, &message, sizeof(message.mtext), 1, IPC_NOWAIT) == -1) {
                if (errno == ENOMSG) {
                    printf("No message available (non-blocking).\n");
                }
		else {
                    perror("msgrcv");
                }
            }
	    else {
                printf("Received (non-blocking): %s\n", message.mtext);
            }
            break;

        default:
            printf("Invalid choice\n");
    }

    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}

/* Output : 
 * $ cc 27receiver.c -o aa.out
 * ==( After sending msg from sender from 2nd terminal...)==
 * $ ./aa.out
 *  1. Blocking Receive
 *  2. Non-Blocking Receive
 *  Enter choice: 1
 *  Received (blocking): Hello from Sender!
 * $ ./aa.out
 *  1. Blocking Receive
 *  2. Non-Blocking Receive
 *  Enter choice: 2
 *  No message available (non-blocking).
 *
 * ==( After resending msg from sender from 2nd terminal...)==
 * $ ./aa.out
 *  1. Blocking Receive
 *  2. Non-Blocking Receive
 *  Enter choice: 2
 *  Received (non-blocking): Hello from Sender!
*/
