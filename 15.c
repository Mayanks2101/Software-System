/*
 ============================================================================
 Name        : 15.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to display the environmental variable of the user (use environ).
 Date        : 25 Aug, 2025
 ============================================================================
*/

// code :

#include <stdio.h>

extern char **environ;

int main() {
    char **env = environ;

    while (*env) {
        printf("%s\n", *env);
        env++;
    }

    return 0;
}

/*
 Output:
 $./a.out
 SHELL=/bin/bash
 SESSION_MANAGER=local/mayank-IdeaPad-5-15ITL05:@/tmp/.ICE-unix/2284,unix/mayank-IdeaPad-5-15ITL05:/tmp/.ICE-unix/2284
 QT_ACCESSIBILITY=1
 COLORTERM=truecolor
 XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
 XDG_MENU_PREFIX=gnome-
 GNOME_DESKTOP_SESSION_ID=this-is-deprecated
 GNOME_SHELL_SESSION_MODE=ubuntu
 SSH_AUTH_SOCK=/run/user/1000/keyring/ssh
 MEMORY_PRESSURE_WRITE=c29tZSAyMDAwMDAgMjAwMDAwMAA=
 XMODIFIERS=@im=ibus
 DESKTOP_SESSION=ubuntu
 GTK_MODULES=gail:atk-bridge
 DBUS_STARTER_BUS_TYPE=session
 PWD=/home/mayank/Mayank/SEM1/OS/lab/list1
 LOGNAME=mayank
 ....
*/
