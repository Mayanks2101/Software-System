/*
 ============================================================================
 Name        : 28.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to change the existing message queue permission. (use msqid_ds structure)
 Date        : 16 Sep, 2025
 ============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key;
    int msgid;
    struct msqid_ds buf;

    key = ftok(".", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    msgctl(msgid, IPC_STAT, &buf);

    printf("Current permissions : %o\n", buf.msg_perm.mode);
    sleep(10);
    printf("Permission will change in 10sec..Verify using ipcs -q\n");

    buf.msg_perm.mode = 0644;

    msgctl(msgid, IPC_SET, &buf);

    printf("Permissions changed to: %o\n", buf.msg_perm.mode);

    return 0;
}
/* Output :
 * $ ./a.out
 *  Current permissions : 666
 *  Permission will change in 10sec..Verify using ipcs -q
 *  Permissions changed to: 644
*/
