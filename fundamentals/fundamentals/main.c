//
//  main.c
//  fundamentals
//
//  Created by Pedro Ontiveros on 3/7/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatypes.h"
#include "utils.h"


#define CITY_LIST_SIZE 10

void testArrayInteger() {
    int  len = rand() / 1000;
    int *ptr = (int*)malloc(sizeof(int) * len);
    int i = 0;
    
    for (i = 0; i < len; i++) {
        ptr[i] = rand() / 100;
    }
    
    printf("Integer array unsorted\n");
    printArrayOfInteger(ptr, len);
    sortInteger(ptr, len);
    printf("\nInteger array sorted\n");
    printArrayOfInteger(ptr, len);
}

void testArrayDouble() {
    int  len = 100;
    double *ptr = (double*)malloc(sizeof(double) * len);
    int i = 0;
    
    for (i = 0; i < len; i++) {
        ptr[i] = rand() / 100.00;
    }
    
    printf("Float array unsorted\n");
    printArrayOfDouble(ptr, len);
    sortDouble(ptr, len);
    printf("\nFloat array sorted\n");
    printArrayOfDouble(ptr, len);
    free(ptr);
}

void testArrayStrings() {
    
    char **ptr = (char**)malloc(sizeof(char*) * CITY_LIST_SIZE);
    
    /* Populated the array */
    addItemToArray(ptr, "New York", 0);
    addItemToArray(ptr, "Chicago", 1);
    addItemToArray(ptr, "Miami", 2);
    addItemToArray(ptr, "San Francisco", 3);
    addItemToArray(ptr, "Buenos Aires", 4);
    addItemToArray(ptr, "Dallas", 5);
    addItemToArray(ptr, "Atlanta", 6);
    addItemToArray(ptr, "Seattle", 7);
    addItemToArray(ptr, "Denver", 8);
    addItemToArray(ptr, "Columbus", 9);
    
    printf("String array unsorted\n");
    printArrayOfStrings(ptr, CITY_LIST_SIZE);
    sortStringList(ptr, CITY_LIST_SIZE);
    
    printf("String array sorted\n");
    printArrayOfStrings(ptr, CITY_LIST_SIZE);
}

void experiment3(const char *source, char** out) {
    unsigned long len = strlen(source);
    *out = (char*)malloc(sizeof(char) * (len + 1));
    memset(*out, 0, len + 1);
    strncpy(*out, source, len);
}

void thirdExperiment() {
    char **outValue = (char**)malloc(sizeof(char*));
    experiment3("My name is Pedro Ontiveros", outValue);
    printf("Hello, this is the new value: %s.\n", *outValue);
    
    free(*outValue);
    experiment3("this is another value", outValue);
    printf("Hello, this is the new value: %s.\n", *outValue);
}


    
int main(int argc, const char * argv[]) {
    /* datatypes();        */
    /* testArrayInteger(); */
    /* testArrayDouble();  */
    testArrayStrings();
    /* thirdExperiment();  */
    printf("\n***** End of program ***** \n");
    return (EXIT_SUCCESS);
}
