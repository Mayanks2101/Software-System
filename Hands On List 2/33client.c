/*
 ============================================================================
 Name        : 33client.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to communicate between two machines using socket.
 Date        : 27 Sep, 2025
 ============================================================================
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define BUFF_SIZE 1024

int main() {
    int sd, portno = 5050;
    struct sockaddr_in serv;
    char buffer[1024];

    //Socket Create
    sd = socket(AF_INET, SOCK_STREAM, 0);
	
    char ip[50];
    printf("Enter Server IP Address : ");
    scanf("%s", ip);

    // Server Address setup
    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = inet_addr(ip);
    serv.sin_port = htons(portno);

    connect(sd, (struct sockaddr*)&serv, sizeof(serv));
    printf("Connected to Server %s:%d\n", ip, portno);

    while(1){
    	printf("Send Message from Client : ");
	fgets(buffer, BUFF_SIZE, stdin);

	write(sd, buffer, strlen(buffer));

    	memset(buffer, 0, sizeof(buffer));
    	read(sd, buffer, sizeof(buffer));
    	printf("\nMessage Received from Server : %s\n", buffer);
    }

    //Close Socket
    close(sd);

    return 0;
}
/* Output :
 * $ hostname -I
	172.16.132.213
 * $ cc 33client.c -o client
 * $ ./client
	Enter Server IP Address : 172.16.132.213
	Connected to Server 172.16.132.213:5050
	Send Message from Client : 
	Message Received from Server : Hello Client..

	Send Message from Client : Hello Server, How Are You?

	Message Received from Server : I am Fine Client, Thank You.

*/

