/*
 ============================================================================
 Name        : 33server.c
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
int main(){
	int sd, nsd, portno = 5050;

	struct sockaddr_in serv, cli;
	socklen_t cli_len;
	char buf[BUFF_SIZE];
	
	//Create Socket
	sd = socket (AF_INET, SOCK_STREAM, 0);
	
	//Server Address Setup
	serv.sin_family = AF_INET;
	serv.sin_addr.s_addr = INADDR_ANY;
	serv.sin_port = htons (portno);
	
	//Bind Socket
	bind (sd, (struct sockaddr*)&serv, sizeof (serv));
	
	//Listen
	listen (sd, 5);
	printf("Server Listening on port %d...\n", portno);

	cli_len = sizeof(cli);
	nsd = accept (sd,(struct sockaddr*)&cli, &cli_len);
	
	printf("Connection Accepted.\n");

	while(1){
		memset(buf, 0, BUFF_SIZE); 
		read(nsd, buf, sizeof(buf));
		printf("Message Received From Client : %s\n", buf);
		
		printf("Send Message from Server : ");
		fgets(buf, BUFF_SIZE, stdin);
		write(nsd, buf, strlen(buf));
	}

	//Close socket
	close(nsd);
	close(sd);
	return 0;

}
/* Output :
 * $ cc 33server.c -o server
 * $ ./server
	Server Listening on port 5050...
	Connection Accepted.
	Message Received From Client : 
	
	Send Message from Server : Hello Client..
	Message Received From Client : Hello Server, How Are You?

	Send Message from Server : I am Fine Client, Thank You.
*/
