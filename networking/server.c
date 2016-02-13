
/**

	This file has been generated by Pedro Ontiveros.
	Filename: server.c
	Author: Pedro Ontiveros.
	email: ontiveros.pedro@gmail.com
	twitter: pontiveros_ar
	Thu Feb  4 02:45:48 2016

**/

/********************************/
/****** TCP/IP Programing *******/
/* This program should work in linux, unix or windows */
/********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_STRING 		256
#define END_CONNECTION "eof"

int main(int argc, char *argv[]) {
	int 	sockfd, newsockfd, port;
	struct sockaddr_in server_addr, client_addr;
	socklen_t client_len;
	char buffer[MAX_STRING];
	int bytes; // read chars from remote connection.

	if (argc < 2) {
		perror("ERROR: port has not been provided.");
		exit(EXIT_FAILURE);
	}

	sockfd = socket(AF_INET, SOCK_STREAM, 0); // create socket.
	if (sockfd < 0) {
		perror("ERROR: opening socket.");
		exit(EXIT_FAILURE);
	}

	port = atoi(argv[1]);
	server_addr.sin_family 		= AF_INET;    // Network family 
	server_addr.sin_addr.s_addr = INADDR_ANY; // Any address can connect ?
	server_addr.sin_port 		= htons(port);

	if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
		perror("ERROR: binding server.");
		exit(EXIT_FAILURE);
	}
	
	listen(sockfd, 5); // 5 means connections at the same time.

	client_len = sizeof(client_addr);
	newsockfd  = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
	if (newsockfd < 0) {
		perror("ERROR: accepting connection.");
		exit(EXIT_FAILURE);	
	}

	memset(buffer, 0, MAX_STRING);
 	/* do { */
		/* bzero(buffer, MAX_STRING); */ /* Check for this function. */
		bytes = recv(newsockfd, buffer, MAX_STRING, 0);
		buffer[bytes] = '\0';

		/* n = read(newsockfd, buffer, MAX_STRING); */
		if (bytes < 0) {
			perror("ERROR: reading socket.");
		} else {
			printf("Remote Message: %s", buffer);
			printf("Bytes: %d", bytes);
		}
	/* } while (strncmp(buffer, END_CONNECTION, 3) != 0); */

	close(sockfd);
	close(newsockfd);

	exit(EXIT_SUCCESS);
}