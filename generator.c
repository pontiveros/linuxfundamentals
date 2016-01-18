

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

char *getdatetime()
{
    char *array = (char*)malloc(sizeof(char)*25);
    time_t result;
    result = time(NULL);
    sprintf(array, "%s", asctime(localtime(&result)));
    array[25] = '\0';
    return array;
}

int main(int argc, char *argv[]) {

	if (argc > 1 && argv != NULL) {

		printf("Start\n");

		FILE *ptr = fopen(argv[1], "w");

		if (ptr) {
			char sDate[30];
			sprintf(sDate, "\t%s\n", getdatetime());

			fputs("\n/**\n\n", ptr);
			fputs("\tThis file has been generated by Pedro Ontiveros.\n", ptr);
			fputs("\tAuthor: Pedro Ontiveros.\n", ptr);
			fputs("\temail: ontiveros.pedro@gmail.com\n", ptr);
			fputs("\ttwitter: pontiveros_ar\n", ptr);
			fputs(sDate, ptr);
			fputs("**/\n", ptr);
			fputs("\n\n#include <stdio.h>\n#include <stdlib.h>\n\n", ptr);
			fputs("\nint main(int argc, char *argv[]) {\n", ptr);
			fputs("\tprintf(\"Hello World!\\n\");", ptr);
			fputs("\n\texit(EXIT_SUCCESS);\n}", ptr);
			
			fclose(ptr);
		}
		printf("End\n");	
	}
	exit(EXIT_SUCCESS);
}