/*
 ============================================================================
 Name        : 2.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to print the system resource limits. Use getrlimit system call.
 Date        : 17 Sep, 2025
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

void print_limit(int resource, const char *name) {
    struct rlimit limit;
    if (getrlimit(resource, &limit) == 0) {
        printf("%-15s Soft: ", name);
        if (limit.rlim_cur == RLIM_INFINITY)
            printf("Unlimited");
        else
            printf("%ld", (long)limit.rlim_cur);

        printf(" | Hard: ");
        if (limit.rlim_max == RLIM_INFINITY)
            printf("Unlimited\n");
        else
            printf("%ld\n", (long)limit.rlim_max);
    } else {
        perror("getrlimit");
    }
}

int main() {
    printf("=== System Resource Limits ===\n");

    print_limit(RLIMIT_CPU, "CPU time");
    print_limit(RLIMIT_FSIZE, "File size");
    print_limit(RLIMIT_DATA, "Data seg size");
    print_limit(RLIMIT_STACK, "Stack size");
    print_limit(RLIMIT_CORE, "Core file size");
    print_limit(RLIMIT_RSS, "Resident set");
    print_limit(RLIMIT_NOFILE, "Open files");
    print_limit(RLIMIT_NPROC, "Processes");
    print_limit(RLIMIT_MEMLOCK, "Locked mem");
    print_limit(RLIMIT_AS, "Address space");

    return 0;
}
/* Output :
 * $ ./a.out
 * === System Resource Limits ===
CPU time        Soft: Unlimited | Hard: Unlimited
File size       Soft: Unlimited | Hard: Unlimited
Data seg size   Soft: Unlimited | Hard: Unlimited
Stack size      Soft: 8388608 | Hard: Unlimited
Core file size  Soft: 0 | Hard: Unlimited
Resident set    Soft: Unlimited | Hard: Unlimited
Open files      Soft: 1024 | Hard: 1048576
Processes       Soft: 30348 | Hard: 30348
Locked mem      Soft: 1014398976 | Hard: 1014398976
Address space   Soft: Unlimited | Hard: Unlimited
 *
*/
