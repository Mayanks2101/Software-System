/*
 ============================================================================
 Name        : 10.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to open a file with read write mode, write 10 bytes,
               move the file pointer by 10 bytes (use lseek) and write again 10 bytes.
               a. check the return value of lseek
               b. open the file with od and check the empty spaces in between the data.
 Date        : 23 Aug, 2025
 ============================================================================
*/

// code :

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd = open("10.txt", O_CREAT | O_RDWR, 0644);
    if (fd == -1) {
        perror("open failed");
        return 1;
    }

    //Write 10 bytes
    char buf1[11] = "ABCDEFGHIJ";
    if (write(fd, buf1, 10) != 10) {
        perror("write 1 failed");
        return 1;
    }

    //Move file pointer 10 bytes forward
    off_t offset = lseek(fd, 10, SEEK_CUR);
    if (offset == -1) {
        perror("lseek failed");
        return 1;
    } else {
        printf("lseek moved to offset: %ld\n", offset);
    }

    //Write 10 bytes
    char buf2[11] = "1234567890";
    if (write(fd, buf2, 10) != 10) {
        perror("write 2 failed");
        return 1;
    }

    close(fd);
    return 0;
}

/*
 Output:
 $./a.out
 lseek moved to offset: 20
 
 $od -c 10.txt
 0000000   A   B   C   D   E   F   G   H   I   J  \0  \0  \0  \0  \0  \0
 0000020  \0  \0  \0  \0   1   2   3   4   5   6   7   8   9   0
 0000036

*/
