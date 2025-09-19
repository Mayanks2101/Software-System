/*
============================================================================
 Name : 7.c
 Author : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to copy file1 into file2 ($cp file1 file2).
 Date: 17 Aug, 2025.
============================================================================
*/

// code :

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int src_fd, dest_fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    if (argc != 3) {
        printf("Please Provide file..");
        return 1;
    }

    src_fd = open(argv[1], O_RDONLY);

    dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);

    while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
	 bytes_written = write(dest_fd, buffer, bytes_read);
    }

    close(src_fd);
    close(dest_fd);

    printf("File copied successfully from '%s' to '%s'\n", argv[1], argv[2]);
    return 0;
}

/* Output : 
 $ ./a.out 7_file1.txt 7_file2.txt
  File copied successfully from '7_file1.txt' to '7_file2.txt'
 $ cat 7_file2.txt
  Hello ! Good Morning
*/
