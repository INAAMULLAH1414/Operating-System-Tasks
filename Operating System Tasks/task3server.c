//server.c (FIFOs)
#include "myheader.h"
int main()
{
	char buff[1024];
	int readfd, writefd, n, size;
	char* msg;
	
	//create fifo1 & fifo2 using mknod system call
	mknod(FIFO1, S_IFIFO | PERMS, 0);
	mknod(FIFO2, S_IFIFO | PERMS, 0);

	//Open fifo1 for read only, for reading a message from client
	readfd = open(FIFO1, 0);
	
	//Open fifo2 for write only, for writing a response to client request
	writefd = open(FIFO2, 1);


	//if client has yet not run, the server process will block
	//on following read. As soon as some client executes and writes some msg in FIFO1, the server process will automatically unblock
	n=read(readfd, buff, strlen(MESSAGE1)+1);

	//Once the client has sent the msg to server, the svr will display that message on screen
	msg = "Request from client: ";
	write(1, msg, strlen(msg));
	write(1, buff, n);


	//Now the server will send a response to the client via fifo2
	sleep(3);
	write(writefd, MESSAGE2, strlen(MESSAGE2) + 1);
	close (readfd);
	close (writefd);

	return 0;
}
