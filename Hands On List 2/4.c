/*
 ============================================================================
 Name        : 4.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to measure how much time is taken to execute 100 getppid ( )
               system call. Use time stamp counter.
 Date        : 19 Sep, 2025
 ============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <x86intrin.h>

int main() {
    unsigned long long start, end;
    int i;

    start = __rdtsc();

    for (i = 0; i < 100; i++) {
        getppid();
    }

    end = __rdtsc();
    int nano = (end - start)/2.4;
    printf("Time taken by CPU for 100 getppid() calls (in nanosec): %d ns\n", nano);

    return 0;
}
/* Output :
 * $ ./a.out
     Time taken by CPU for 100 getppid() calls (in nanosec): 38224 ns
*/
