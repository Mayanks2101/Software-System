/*
 ============================================================================
 Name        : 19.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to find out time taken to execute getpid system call.
               Use time stamp counter.
 Date        : 30 Aug, 2025
 ============================================================================
*/

// code :

#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>
#include<x86intrin.h>

int main (void){
	int nano;
	unsigned long long int start, end;
	start = _rdtsc();

	getpid();

	end = _rdtsc();

	nano = (end - start)/2.4;
	printf("The getpid system call takes %d nano sec\n", nano);
}

/*
 Output:
 $ ./a.out
 The getpid system call takes 5450 nano sec
*/
