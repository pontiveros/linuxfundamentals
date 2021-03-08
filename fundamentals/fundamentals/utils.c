//
//  utils.c
//  fundamentals
//
//  Created by Pedro Ontiveros on 3/7/21.
//

#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void integerSwap(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void doubleSwap(double *a, double *b) {
    double aux = *a;
    *a = *b;
    *b = aux;
}

char *duplicateString(char *source) {
    unsigned long n = strlen(source);
    char *result = (char*)malloc(sizeof(char) * (n + 1));
    memset(result, 0, n + 1);
    strncpy(result, source, n);
    printf("\n%s\n", result);
    return result;
}

void addItemToArray(char **ptr, char *value, int index) {
    unsigned long len = strlen(value);
    ptr[index] = (char*)malloc(sizeof(char) * (len + 1));
    memset(ptr[index], 0, len + 1);
    strncpy(ptr[index], value, len);
}

void stringsSwap(char *a, char *b) {
    char *tmp = duplicateString(a);
    free(a);
    
    a = duplicateString(b);
    free(b);
    
    b = duplicateString(tmp);
    free(tmp);
}

void printArrayOfInteger(int *ptr, int len) {
    int i = 0;
    for (i = 0; i < len; i++) {
        printf("Order %02d value:\t%d\n", i, ptr[i]);
    }
}

void printArrayOfDouble(double *ptr, int len) {
    int i = 0;
    for (i = 0; i < len; i++) {
        printf("Order %02d value:\t%lf\n", i, ptr[i]);
    }
}

void printArrayOfStrings(char *ptr[], int len) {
    int i = 0;
    for (i = 0; i < len; i++) {
        printf("Order %02d value:\t%s\n", i, ptr[i]);
    }
}

void sortInteger(int *ptr, int len) {
    int i, j = 0;
    for (i = 0; i < (len - 1); i++) {
        for (j = i + 1; j < len; j++) {
            if (ptr[i] > ptr[j]) {
                integerSwap(&ptr[i], &ptr[j]);
            }
        }
    }
}

void sortDouble(double *ptr, int len) {
    int i, j = 0;
    for (i = 0; i < (len - 1); i++) {
        for (j = i + 1; j < len; j++) {
            if (ptr[i] > ptr[j]) {
                doubleSwap(&ptr[i], &ptr[j]);
            }
        }
    }
}

void sortStringList(char *ptr[], int len) {
    int i, j = 0;
    
    for (i = 0; i < (len - 1); i++) {
        for (j = i + 1; j < len; j++) {
            if (strcmp(ptr[i], ptr[j]) > 0) {
                stringsSwap(ptr[i], ptr[j]);
            }
        }
    }
}
