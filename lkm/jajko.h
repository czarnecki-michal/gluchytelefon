#ifndef _JAJKO_H_
#define _JAJKO_H_
#include <sys/types.h>
#define BUFFER_SIZE 32

static ssize_t dev_read(struct file *, char *, size_t, loff_t *);
static ssize_t dev_write(struct file *, const char *, size_t, loff_t *);

#endif