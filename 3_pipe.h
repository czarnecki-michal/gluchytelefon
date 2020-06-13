#ifndef _3_PIPE_H_
#define _3_PIPE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <math.h>

long int receive();
long int transform(long int);
int bin2dec(long);
long int set_bit(unsigned int, unsigned int);

#endif