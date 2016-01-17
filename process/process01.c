

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void worker() {
	// Simulating worker, kill the process with kill command and see the results.
	int n = 0;
	for (n = 0; n < 120; n++) {
		sleep(1);
		printf("Cycle %d\n", n + 1);
	}
}

int main(int argc, char *argv[]) {
	printf("Process Id: %d\n", getpid());
	printf("Parent Process Id: %d\n", getppid());
	worker();
	exit(EXIT_SUCCESS);
}
