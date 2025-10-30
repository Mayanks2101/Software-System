/*
 ============================================================================
 Name        : 28.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to get maximum and minimum real time priority.
 Date        : 6 Sept, 2025
 ============================================================================
*/

// code :

#include <stdio.h>
#include <sched.h>

int main() {
    int max_fifo = sched_get_priority_max(SCHED_FIFO);
    int min_fifo = sched_get_priority_min(SCHED_FIFO);

    int max_rr = sched_get_priority_max(SCHED_RR);
    int min_rr = sched_get_priority_min(SCHED_RR);

    printf("SCHED_FIFO: Max Priority = %d, Min Priority = %d\n", max_fifo, min_fifo);
    printf("SCHED_RR  : Max Priority = %d, Min Priority = %d\n", max_rr, min_rr);

    return 0;
}

/*
 Output:
 $ ./a.out
 SCHED_FIFO: Max Priority = 99, Min Priority = 1
 SCHED_RR  : Max Priority = 99, Min Priority = 1
 
 (To verify)
 $ chrt -max
 SCHED_OTHER min/max priority	: 0/0
 SCHED_FIFO min/max priority	: 1/99
 SCHED_RR min/max priority	: 1/99
 SCHED_BATCH min/max priority	: 0/0
 SCHED_IDLE min/max priority	: 0/0
 SCHED_DEADLINE min/max priority	: 0/0

*/
