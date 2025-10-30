/*
 ============================================================================
 Name        : 14.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to find the type of a file.
               a. Input should be taken from command line.
               b. program should be able to identify any type of a file.
 Date        : 24 Aug, 2025
 ============================================================================
*/

// code :

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    struct stat st;

    if (argc != 2) {
        printf("Please provide file name");
        exit(1);
    }

    if (stat(argv[1], &st) == -1) {
        perror("stat");
        exit(1);
    }

    if (S_ISREG(st.st_mode))
        printf("Regular file\n");
    else if (S_ISDIR(st.st_mode))
        printf("Directory\n");
    else if (S_ISLNK(st.st_mode))
        printf("Symbolic link\n");
    else if (S_ISCHR(st.st_mode))
        printf("Character device\n");
    else if (S_ISBLK(st.st_mode))
        printf("Block device\n");
    else if (S_ISFIFO(st.st_mode))
        printf("FIFO (named pipe)\n");
    else if (S_ISSOCK(st.st_mode))
        printf("Socket\n");
    else
        printf("Unknown file type\n");

    return 0;
}

/*
 Output:
 $ ./a.out 14.txt
 Regular file
*/
