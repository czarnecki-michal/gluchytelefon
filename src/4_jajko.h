#ifndef _2_ARGUMENT_H_
#define _2_ARGUMENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

long int receive();
unsigned int reverse_bits(unsigned int);
void send(const unsigned int);

#endif
