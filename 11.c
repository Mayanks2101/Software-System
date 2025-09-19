/*
 ============================================================================
 Name        : 11.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to open a file, duplicate the file descriptor and
               append the file with both the descriptors and check whether the file
               is updated properly or not.
               a. use dup
               b. use dup2
               c. use fcntl
 Date        : 23 Aug, 2025
 ============================================================================
*/

// code :

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd1, fd2, fd3, fd4;

    fd1 = open("11.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd1 < 0) {
        perror("open failed");
        return 1;
    }

    fd2 = dup(fd1);
    if (fd2 < 0) {
        perror("dup failed\n");
        return 1;
    }

    fd3 = dup2(fd1, 100);
    if (fd3 < 0) {
        perror("dup2 failed\n");
        return 1;
    }

    fd4 = fcntl(fd1, F_DUPFD, 200);
    if (fd4 < 0) {
        perror("fcntl failed\n");
        return 1;
    }

    write(fd1, "Written from original file\n", 28);
    write(fd2, "Written from dup created file\n", 31);
    write(fd3, "Written from dup2 created file\n", 32);
    write(fd4, "Written from fcntl\n", 20);

    close(fd1);
    close(fd2);
    close(fd3);
    close(fd4);

    return 0;
}

/*
 Output:
 $./a.out
 $ cat 11.txt
  Written from original file
  Written from dup created file
  Written from dup2 created file
  Written from fcntl
*/
