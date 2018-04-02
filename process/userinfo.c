

/*
	Get user info by C API on POSIX
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int main() {
	struct passwd *pass;

	char *user_name = getlogin();
	if (user_name == NULL) {
		perror("Error geting user name");
		exit(EXIT_FAILURE);
	}

	printf("UserName: %s\n", user_name);

	pass = getpwnam(user_name);
	if (pass == NULL) {
		perror("Error geting user password");
		exit(EXIT_FAILURE);
	}
	printf("gecos: %s\n", pass->pw_gecos);

	exit(EXIT_SUCCESS);
}