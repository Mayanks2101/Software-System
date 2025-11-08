/*
 ============================================================================
 Name        : 34b_server.c
 Author      : Mayankkumar Satapara
 Roll Number : MT2025069
 Description : Write a program to create a concurrent server.
               a. use fork
               b. use pthread_create
 Date        : 28 Sep, 2025
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define BUFF_SIZE 1024

void *handle_client(void *nsdAddr){
	char buf[BUFF_SIZE];
	int n;
	int nsd = *(int *)nsdAddr;

	while(1){
		memset(buf, 0, BUFF_SIZE);
                read(nsd, buf, sizeof(buf));
                printf("Message Received From Client : %s\n", buf);

                //printf("Send Message from Server : ");
                //fgets(buf, BUFF_SIZE, stdin);
		write(nsd, buf, strlen(buf));
	}
	close(nsd);
	pthread_exit(NULL);
}

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
	printf("Concurrent Server Listening on port %d...\n", portno);

	while(1){
		cli_len = sizeof(cli);
	        nsd = accept (sd,(struct sockaddr*)&cli, &cli_len);
	        printf("Connection Accepted.\n");
	
		pthread_t tid;
		int *nsdAddr = malloc(sizeof(int));
		*nsdAddr = nsd;

		if(pthread_create(&tid, NULL, handle_client, nsdAddr) != 0){
			perror("pthread_creat failed");
			close(nsd);
		}
		pthread_detach(tid);
	}
	close(sd);
	return 0;
}

/* Output :
 * ==> TERMINAL 1
 * $ cc 34b_server.c -o server
 * $ ./server
	Concurrent Server Listening on port 5050...
	Connection Accepted.
	Message Received From Client : 
	
	Connection Accepted.
	Message Received From Client : 

	Message Received From Client : Hello I am Client1

	Message Received From Client : Hello I am Client2

 * ==> TERMINAL 2
 * $ cc 34b_client.c -o client
 * $ ./client
	Enter Server IP Address : 127.0.0.1
	Connected to Server 127.0.0.1:5050
	Send Message from Client : 
	Message Received from Server : 
	
	Send Message from Client : Hello I am Client1
	
	Message Received from Server : Hello I am Client1

 * ==> TERMINAL 3 
 * $ cc 34b_client.c -o client
 * $ ./client
	Enter Server IP Address : 127.0.0.1
	Connected to Server 127.0.0.1:5050
	Send Message from Client : 
	Message Received from Server : 
	
	Send Message from Client : Hello I am Client2 
	
	Message Received from Server : Hello I am Client2
*/
