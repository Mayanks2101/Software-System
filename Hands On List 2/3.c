/*
 ============================================================================
 Name        : 3.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to set (any one) system resource limit. Use setrlimit system call.
 Date        : 18 Sep, 2025
 ============================================================================
*/

#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit limit;

    getrlimit(RLIMIT_NOFILE, &limit);
    printf("Before: soft=%ld hard=%ld\n", (long)limit.rlim_cur, (long)limit.rlim_max);

    limit.rlim_cur = 2048;
    if (setrlimit(RLIMIT_NOFILE, &limit) == -1) {
        perror("setrlimit");
        return 1;
    }

    getrlimit(RLIMIT_NOFILE, &limit);
    printf("After:  soft=%ld hard=%ld\n", (long)limit.rlim_cur, (long)limit.rlim_max);

    return 0;
}
/* Output :
 * $ ./a.out
    Before: soft=1024 hard=1048576
    After:  soft=2048 hard=1048576
*/  

