/*
 ============================================================================
 Name        : 30.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to run a script at a specific time using a Daemon process.
 Date        : 6 Sept, 2025
 ============================================================================
*/

// code :


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]){
	int hh = atoi(argv[1]);
	int mm = atoi(argv[2]);

	if( !fork() ){
		setsid();
		//chdir("/");
		umask(0);
	
		while(1) {
			time_t now = time(NULL);
        		struct tm *t = localtime(&now);

        		if (t->tm_hour == hh && t->tm_min == mm) 
			{
            			printf("Child Process : %d\n", getpid());
                        	printf("Daemon process is running ... ");
				system("./30script.sh");
            			
				sleep(60);
			}

        		sleep(10);
		}
	}
	else{
		exit(0);
	}
}


/*
 Output:
 $ ./a.out 23 38
 Child Process : 20258

 (Output of 30script.sh)
 $ Script run at Sat Sep  6 11:38:49 PM IST 2025
 
 $ kill 20258
*/
