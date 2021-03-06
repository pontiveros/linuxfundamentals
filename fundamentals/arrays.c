/**

	This file has been generated by Pedro Ontiveros.
	Filename: ../../fundamentals/arrays.c
	Author: Pedro Ontiveros.
	email: ontiveros.pedro@gmail.com
	twitter: pontiveros_ar
	Wed Mar  3 00:26:25 EST 2021

    clang: 
    $ clang -g source.c -o {binaryFile} ==> Result binary file + dsymb

    debug: 
    $ lldb {binary file} (object file)
    $ breakpoint set -file {source filename} --line {line}
    $ br s -f {source filename} -l {line}
    $ b {source filename} -l {line}
    $ next or n

**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

#define MAX_STRING 100

char* generateStrings(int lengh) {
    int i = 0; 
    char *pszText = (char*)malloc(sizeof(char) * (lengh + 1));
    memset(pszText, 0, lengh + 1);

    for (i = 0; i < lengh; i++) {
        pszText[i] = (char)(rand() % 26);
    }

    return pszText;
}

void testArrayInteger() {
    printf("Testing array of integer.\n");
}

void testArrayFloat() {
    printf("Testing array of float.\n");
}

void testArrayStrings() {
    printf("Testing array of string.\n");
}

int main(int argc, char* argv[]) {
    int  sel = 0;
    char rsp = 'n';
    const char * items[] = {"Generate an array of:", "1- Integer", "2- Float", "2- Strings", "0- Exit"};
    /* char * pszLine = NULL; */

    do {
        cleanScreen();
        sel = selectMenu(items, 5);
        switch (sel) {
            case 1: testArrayInteger(); break;
            case 2: testArrayFloat();   break;
            case 3: testArrayStrings(); break;
        }
        fflush(stdin);
        printf("Continue?[Y/n]:");
        scanf("%c",&rsp);
    } while ((char)rsp == 'Y' || (char)rsp == 'y');
    
    /* The previous one is more clean way to send the parameter. */
    /* sel = selectMenu((const char *[] ){"Generate an array of:", "1- Integer", "2- Float", "0- Exit"}, 4); */
   
    printf("End of program\n");
    exit(EXIT_SUCCESS);    
}