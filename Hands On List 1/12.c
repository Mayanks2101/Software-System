/*
 ============================================================================
 Name        : 12.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to find out the opening mode of a file. Use fcntl.
 Date        : 24 Aug, 2025
 ============================================================================
*/

// code :

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int fd = open("12.txt", O_RDWR | O_CREAT, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    int flags = fcntl(fd, F_GETFL);
    if (flags < 0) {
        perror("fcntl");
        return 1;
    }
	
    int access_mode = flags & O_ACCMODE;
	
    if (access_mode == O_RDONLY)
        printf("File opened in read-only mode\n");
    else if (access_mode == O_WRONLY)
        printf("File opened in write-only mode\n");
    else if (access_mode == O_RDWR)
        printf("File opened in read-write mode\n");
    else
        printf("Unknown file access mode\n");

    close(fd);
    return 0;
}

/*
 Output:
 $ ./a.out
 File opened in read-write mode
*/
