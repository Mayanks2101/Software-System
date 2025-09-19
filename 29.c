/*
 ============================================================================
 Name        : 29.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to get scheduling policy and modify the scheduling
               policy (SCHED_FIFO, SCHED_RR).
 Date        : 6 Sept, 2025
 ============================================================================
*/

// code :

#include<sys/types.h>
#include<sched.h>
#include<stdio.h>
#include<unistd.h>

struct sched_param p;

int main() {
	p.sched_priority = 10;
	printf("The SetScheduler returns %d\n", sched_setscheduler(0, SCHED_FIFO, &p));
	printf("The Scheduling Policy is %d\n", sched_getscheduler(getpid()));
	p.sched_priority = 20;
	printf("The SetScheduler returns %d\n", sched_setscheduler(0, SCHED_RR, &p));
	printf("The Scheduling Policy is %d\n", sched_getscheduler(getpid()));
	return 0;
}

/*
 Output:
 $ sudo ./a.out
 [sudo] password for mayank: 
 The SetScheduler returns 0
 The Scheduling Policy is 1
 The SetScheduler returns 0
 The Scheduling Policy is 2

NOTE : 
 sched_getscheduler() returns the policy of the process:

 SCHED_OTHER = 0
 SCHED_FIFO = 1
 SCHED_RR = 2
*/
