/*
 ============================================================================
 Name : 1b.c
 Author : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : 1. Create the following types of a files using (ii) system call
                       b. hard link
 Date: 15 Aug, 2025.
 ============================================================================
*/

//code :

#include <unistd.h>
#include <stdio.h>

int main() {
	if (link("folder/hlink", "hlinked_syscall") == -1) {
        	perror("link");
        	return 1;
    	}
	else{
		printf("Hard Link named \"hlinked_syscall\" Created Successfully Using system call\n");
	}
	return 0;
}

/*
 Output :

 ./a.out
 ls -l | grep 'hlinked_syscall'
 hlinked_syscall
*/

