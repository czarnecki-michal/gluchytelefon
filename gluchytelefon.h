#ifndef _GLUCHYTELEFON_H_
#define _GLUCHYTELEFON_H_

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define BUFFER_SIZE 255

typedef enum infoType
{
    INFO,
    ERROR,
    INPUT,
    OK,
    OUTPUT
} infoType;

bool checkRange(const long int);
void logger(infoType, char[]);

#endif