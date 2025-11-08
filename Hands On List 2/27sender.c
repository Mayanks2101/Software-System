/*
 ============================================================================
 Name        : 27sender.c
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
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX 100

struct msgbuf {
    long mtype;
    char mtext[MAX];
};

int main() {
    key_t key;
    int msgid;
    struct msgbuf message;

    key = ftok(".", 'b');
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    message.mtype = 1;
    strcpy(message.mtext, "Hello from Sender!");

    if (msgsnd(msgid, &message, sizeof(message.mtext), 0) == -1) {
        perror("msgsnd");
        exit(1);
    }

    printf("Message sent: %s\n", message.mtext);
    return 0;
}
/* Output :
 * $ ./a.out
 *  Message sent: Hello from Sender!
*/
