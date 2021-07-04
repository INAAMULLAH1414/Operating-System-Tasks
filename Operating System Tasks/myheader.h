//myheader.h (FIFOs)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/errno.h>
#define FIFO1 "/tmp/fifo1"
#define FIFO2 "/tmp/fifo2"
#define PERMS 0666
#define MESSAGE1 "Hello, server process, kindly add these numbers: 2, 3\n\n"
#define MESSAGE2 "Hello client, the result is: 5\n\n"
#define MESSAGE3 "The result is correct\n"
