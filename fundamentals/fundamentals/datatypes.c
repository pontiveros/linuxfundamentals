//
//  datatypes.c
//  fundamentals
//
//  Created by Pedro Ontiveros on 3/7/21.
//

#include "datatypes.h"

void datatypes() {
    char    c = 'c';
    short   s = 1;
    int     i = 1000;
    long    l = 10000000;
    float   f = 1092.92;
    double  d = 91928.99882;
    char *ptr1 = "Hello";
    void *ptr2 = NULL;

    printf("char size : \t%ld bytes - char value %c\n", sizeof(c), c);
    printf("short size : \t%ld bytes - short value %d\n", sizeof(s), s);
    printf("int size : \t\t%ld bytes - integer value %d\n", sizeof(i), i);
    printf("long size : \t%ld bytes - long value %ld\n", sizeof(l), l);
    printf("float size : \t%ld bytes - float value %f\n", sizeof(f), f);
    printf("double size : \t%ld bytes - double value %lf\n", sizeof(d), d);
    printf("char pointer size : \t%ld bytes - double value %s\n", sizeof(ptr1), ptr1);
    printf("void pointer size : \t%ld bytes - double value NULL\n", sizeof(ptr2));
}
