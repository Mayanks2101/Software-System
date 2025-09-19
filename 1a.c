/*
 ============================================================================
 Name : 1a.c
 Author : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : 1. Create the following types of a files using (ii) system call
                       a. soft link
 Date: 15 Aug, 2025.
 ============================================================================
*/

//code :

#include <unistd.h>
#include <stdio.h>

int main(){
	if (symlink("/folder/slink", "slinked_syscall") == -1) {
		perror("symlink");
        	return 1;
    	}
	else{
		printf("Soft Link named \"slinked_syscall\" created successfully using system call\n");
	}
	return 0;
}

/*
 Output :
 
 ./a.out
 ls -l | grep 'slinked_syscall'
  slinked_syscall -> /folder/slink
*/
