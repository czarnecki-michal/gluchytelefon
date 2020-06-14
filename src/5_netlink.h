#ifndef _5_NETLINK_H_
#define _5_NETLINK_H_

#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/un.h>
#include <fcntl.h>

void n_send(const unsigned int);
long int parse_args(int, char *[]);
long int transform(long int);

#endif