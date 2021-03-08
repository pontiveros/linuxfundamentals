//
//  utils.h
//  fundamentals
//
//  Created by Pedro Ontiveros on 3/7/21.
//

#ifndef __utils_h__
#define __utils_h__

#include <stdio.h>

void printArrayOfInteger(int *ptr, int len);
void printArrayOfDouble(double *ptr, int len);
void printArrayOfStrings(char *ptr[], int len);

void addItemToArray(char **ptr, char *value, int index);
void sortInteger(int *ptr, int len);
void sortDouble(double *ptr, int len);
void sortStringList(char *ptr[], int len);

#endif /* __utils_h__ */
