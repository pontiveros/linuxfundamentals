
#include <stdio.h>
#include "sample1.h"

void printMessage(char *message) {
	if (message) {
		printf("Message: %s\n", message);
	}
}

double sumDouble(double a, double b) {
	return a + b;
}