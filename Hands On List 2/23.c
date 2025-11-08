/*
 ============================================================================
 Name        : 23.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to print the maximum number of files can be opened within a process and
               size of a pipe (circular buffer).
 Date        : 11 Sep, 2025
 ============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    long PIPE_BUF, OPEN_MAX;

    PIPE_BUF = pathconf(".", _PC_PIPE_BUF);
    OPEN_MAX = sysconf(_SC_OPEN_MAX);

    printf("Pipe_buf = %ld\t OPEN_MAX = %ld\n", PIPE_BUF, OPEN_MAX);
    return 0;
}
/* Output : 
 * $ ./a.out
 * Pipe_buf = 4096	 OPEN_MAX = 1024
*/
