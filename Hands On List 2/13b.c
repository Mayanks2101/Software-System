/*
 ============================================================================
 Name        : 13b.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
               will send the signal (using kill system call). Find out whether the first program is able to catch
               the signal or not.
 Date        : 28 Sep, 2025
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <PID>\n", argv[0]);
        return 1;
    }

    pid_t pid = atoi(argv[1]);

    printf("Sending SIGSTOP to PID: %d\n", pid);
    kill(pid, SIGSTOP);

    return 0;
}
/* Output : (Run 13a.c and use that pid)
 * $ cc 13b.c -o aa.out
 * $ ./aa.out
 * $ ./aa.out 11024
	Sending SIGSTOP to PID: 11024
*/
