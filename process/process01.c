

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void worker() {
	/* Simulating worker, kill the process with kill command and see the results. */
	int n = 0;
	for (n = 0; n < 120; n++) {
		sleep(1);
		printf("Cycle %d\n", n + 1);
	}
}

void identifiers() {
	/* By terminal try with id command, only for check. */
	printf("id user: %d\n", getuid());
	printf("id effective user: %d\n", geteuid());
	printf("id group: %d\n", getgid());
	printf("id effective group: %d\n", getegid());
}

void processId() {
	printf("Process Id: %d\n", getpid());
	printf("Parent Process Id: %d\n", getppid());
}

int main(int argc, char *argv[]) {
	processId();
	printf("-----------------------------\n");
	identifiers();
	worker();
	exit(EXIT_SUCCESS);
}
