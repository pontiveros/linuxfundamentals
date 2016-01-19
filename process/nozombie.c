
/**

	This file has been generated by Pedro Ontiveros.
	Filename: nozombie.c
	Author: Pedro Ontiveros.
	email: ontiveros.pedro@gmail.com
	twitter: pontiveros_ar
	Tue Jan 19 00:24:39 2016

**/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char *argv[]) {
	pid_t child;
	int condition;

	if ((child = fork()) == -1) {
		perror("ERROR: fork");
		exit(EXIT_FAILURE);

	} else if (child == 0) {
		puts("Child Process");
		printf("Child PID: %d\n", getpid());
		printf("Child PPID: %d\n", getppid());
		exit(EXIT_SUCCESS);

	} else {
		waitpid(child, &condition, 0);
		puts("Parent Process");
		printf("Parent PID: %d\n", getpid());
		printf("Parent PID: %d\n", getppid());
		printf("Child Result: %d\n", condition);
		
	}

	exit(EXIT_SUCCESS);
}