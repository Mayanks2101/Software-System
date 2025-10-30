/*
 ============================================================================
 Name        : 9.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to print the following information about a given file.
               a. inode
               b. number of hard links
               c. uid
               d. gid
               e. size
               f. block size
               g. number of blocks
               h. time of last access
               i. time of last modification
               j. time of last change
 Date        : 23 Aug, 2025
 ============================================================================
*/

// code :

#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {
        	printf("Please provide filename\n");
        	return 1;
	}
	
	struct stat fileStat;
	if (stat(argv[1], &fileStat) == -1) {
		perror("stat");
	        return 1;
	}

	printf("File: %s\n", argv[1]);
	printf("a. Inode number        : %lu\n", fileStat.st_ino);
	printf("b. Number of links     : %lu\n", fileStat.st_nlink);
    	printf("c. UID (owner)         : %u\n", fileStat.st_uid);
    	printf("d. GID (group)         : %u\n", fileStat.st_gid);
    	printf("e. Size in bytes       : %ld\n", fileStat.st_size);
    	printf("f. Block size          : %ld\n", fileStat.st_blksize);
    	printf("g. Number of blocks    : %ld\n", fileStat.st_blocks);
    	printf("h. Last access time    : %s", ctime(&fileStat.st_atime));
    	printf("i. Last modification   : %s", ctime(&fileStat.st_mtime));

	return 0;
}

/*
 Output:
 $./a.out 9.txt
 File: 9.txt
 a. Inode number        : 131283
 b. Number of links     : 1
 c. UID (owner)         : 1000
 d. GID (group)         : 1000
 e. Size in bytes       : 21
 f. Block size          : 4096
 g. Number of blocks    : 8
 h. Last access time    : Sat Sep  6 22:25:11 2025
 i. Last modification   : Sat Sep  6 22:25:05 2025

*/
