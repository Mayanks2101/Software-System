/*
 ============================================================================
 Name        : 5.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to print the system limitation of
               a. maximum length of the arguments to the exec family of functions.
               b. maximum number of simultaneous process per user id.
               c. number of clock ticks (jiffy) per second.
               d. maximum number of open files
               e. size of a page
               f. total number of pages in the physical memory
               g. number of currently available pages in the physical memory.
 Date        : 20 Sep, 2025
 ============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main() {
    printf("a. Maximum length of arguments to exec functions: %ld\n", sysconf(_SC_ARG_MAX));
    printf("b. Maximum number of simultaneous processes per user ID: %ld\n", sysconf(_SC_CHILD_MAX));
    printf("c. Number of clock ticks (jiffy) per second: %ld\n", sysconf(_SC_CLK_TCK));
    printf("d. Maximum number of open files: %ld\n", sysconf(_SC_OPEN_MAX));
    printf("e. Size of a page: %ld bytes\n", sysconf(_SC_PAGESIZE));

    struct sysinfo info;
    sysinfo(&info);

    printf("f. Total number of pages in the physical memory: %ld\n", sysconf(_SC_PAGESIZE));
    printf("g. Number of currently available pages in the physical memory: %ld\n",sysconf(_SC_PAGESIZE));

    return 0;
}
/* Output :
 * $ ./a.out
	a. Maximum length of arguments to exec functions: 2097152
	b. Maximum number of simultaneous processes per user ID: 30348
	c. Number of clock ticks (jiffy) per second: 100
	d. Maximum number of open files: 1024
	e. Size of a page: 4096 bytes
	f. Total number of pages in the physical memory: 4096
	g. Number of currently available pages in the physical memory: 4096
*/
