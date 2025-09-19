/*
 ============================================================================
 Name        : 2.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a simple program to execute in an infinite loop at the back
               ground. Go to /proc directory and
               identify all the process related information in the corresponding proc directory.
 Date        : Aug 16, 2025
 ============================================================================
*/

// code :

#include <unistd.h>

int main() {
	 while (1) {
		 sleep(1);
	 }
	 return 0;
}

/*
 Output:
 $./a.out &
  [1] 12650
 
 $ cat /proc/12650/stat
  12650 (a.out) S 11826 12650 11826 34818 12660 4194304 121 0 0 0 0 0 0 0 20 0 1 0 3819827 2609152 326 18446744073709551615 97688288468992 97688288469357 140732807829328 0 0 0 0 0 0 1 0 0 17 0 0 0 0 0 0 97688288480696 97688288481296 97688455057408 140732807836046 140732807836054 140732807836054 140732807839728 0

 $ cat /proc/12650/status
 Name:	a.out
 Umask:	0002
 State:	S (sleeping)
 Tgid:	12650
 Ngid:	0
 Pid:	12650
 PPid:	11826
 ...etc.

 $ ls -l /proc/12650/fd
 total 0
 lrwx------ 1 mayank mayank 64 Sep  7 19:41 0 -> /dev/pts/2
 lrwx------ 1 mayank mayank 64 Sep  7 19:41 1 -> /dev/pts/2
 lrwx------ 1 mayank mayank 64 Sep  7 19:41 2 -> /dev/pts/2


*/
