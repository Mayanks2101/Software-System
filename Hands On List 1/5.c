/*
 ============================================================================
 Name        : 5.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to create five new files with infinite loop.
               Execute the program in the background and check the file descriptor
               table at /proc/pid/fd.
 Date        : 17 Aug, 2025
 ============================================================================
*/

// code :

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    char *names[] = {"5a.txt", "5b.txt", "5c.txt", "5d.txt", "5e.txt"};
    while (1) {
        printf("File Descriptor values are :");
	for (int i = 0; i < 5; i++) {
            int fd = open(names[i], O_CREAT | O_RDWR, 0644);
            if (fd == -1) {
                perror("open failed");
                return 1;
            }
	    printf("%d ", fd);
            sleep(2);
        }
	printf("\n");
    }

    return 0;
}

/*
 Output:
 $./a.out
 File Descriptor values are :3 4 5 6 7
*/
