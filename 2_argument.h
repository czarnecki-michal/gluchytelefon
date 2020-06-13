#ifndef _2_ARGUMENT_H_
#define _2_ARGUMENT_H_

#include <errno.h>  
#include <limits.h> 
#include <stdlib.h> 
#include <stdbool.h> 
#include <unistd.h>
#include <getopt.h>

int argv_to_int(char *);
long int transform(long int);
bool is_prime(int);
long int find_prime(long int);
long int parse_args(int, char *[]);

#endif