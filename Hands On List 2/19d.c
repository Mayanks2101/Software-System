/*
 ============================================================================
 Name        : 19d.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Create a FIFO file by
               a. mknod command
               b. mkfifo command
               c. use strace command to find out, which command (mknod or mkfifo) is better.
               d. mknod system call
               e. mkfifo library function
 Date        : 07 Sep, 2025
 ============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>

int main() {
    mknod("19_fifo_mknod_syscall", S_IFIFO | 0666, 0);
    return 0;
}

/* Output : 
 * $ ./a.out
 * $ ls -l | grep '19_fifo'
 *  prw-rw-r-- 1 mayank mayank     0 Sep 21 15:36 19_fifo_mknod_syscall
*/
