/*
 ============================================================================
 Name        : 22.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program, open a file, call fork, and then write to the file by both
               the child as well as the parent processes. Check output of the file.
 Date        : 31 Aug, 2025
 ============================================================================
*/

// code :

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int fd = open("22.txt", O_WRONLY);

	if(!fork()){
		write(fd, "This is written by child\n", 25);
	}
	else{
		write(fd, "This is written by parent\n", 26);
	}
}


/*
 Output:
 $ ./a.out
 $ cat 22.txt
 This is written by parent
 This is written by child
*/
