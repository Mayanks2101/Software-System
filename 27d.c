/*
 ============================================================================
 Name        : 27d.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to execute ls -Rl by the following system calls
               a. execl
               b. execlp
               c. execle
               d. execv
               e. execvp
 Date        : 5 Sept, 2025
 ============================================================================
*/

// code :

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char *args[] = { "ls", "-Rl", NULL };
    pid_t pid = fork();

    if (pid == 0) {
        execv("/bin/ls", args);
        perror("execv failed");
        exit(1);
    } else {
        wait(NULL);
    }

    return 0;
}

/*
 Output:
 $ ./a.out
 .:
 total 252
 -rw-rw-r-- 1 mayank mayank  1573 Sep  6 22:32  10.c
 -rw-r--r-- 1 mayank mayank    30 Sep  6 22:27  10.txt
 -rw-rw-r-- 1 mayank mayank  1562 Sep  6 22:41  11.c
 -rw-r--r-- 1 mayank mayank   111 Sep  6 22:40  11.txt
 -rw-rw-r-- 1 mayank mayank  1130 Sep  6 22:49  12.c
 -rw-r--r-- 1 mayank mayank     0 Aug 17 12:46  12.txt
 -rw-rw-r-- 1 mayank mayank  1323 Sep  6 22:53  13.c
 -rw-rw-r-- 1 mayank mayank  1346 Sep  6 22:57  14.c
 ...

 ./folder:
 total 8
 -rw-rw-r-- 1 mayank mayank 20 Aug 15 18:50 hlink
 -rw-rw-r-- 1 mayank mayank 20 Aug 15 18:50 slink
*/
