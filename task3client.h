// client.c (FIFOs)
#include "header.h"

int task3client()
{
	char buff[1024];
	int readfd, writefd, n, size;
	char *msg;

	// open fifo1 for writing
	writefd = open(FIFO1, 1);
	// open fifo2 for reading
	readfd = open(FIFO2, 0);

	// Client write a message in fifo1 to be sent to server
	write(writefd, MESSAGE1, strlen(MESSAGE1) + 1);

	// Now the client will read the fifo1 to read the msg sent by server
	n = read(readfd, buff, strlen(MESSAGE2) + 1);

	// Now the client will display the msg sent by server on screen
	msg = "Response from server: ";
	write(1, msg, strlen(msg));
	write(1, buff, n);

	sleep(1);
	write(1, MESSAGE3, strlen(MESSAGE3));

	close(readfd);
	close(writefd);
	// remove fifos now that we are done using them
	if (unlink(FIFO1) < 0 || unlink(FIFO2) < 0)
	{
		perror("Client unlink FIFO1 or FIFO2");
		exit(1);
	}

	return 0;
}
