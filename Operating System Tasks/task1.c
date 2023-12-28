#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int cpid;
	cpid = fork();

	if (cpid == -1)
	{
		printf("Fork failed\n");
		exit(1);
	}

	if (cpid == 0)
	{
		printf("Hello! I am child and my PID is:%ld\n", (long)getpid());
	}
	else
	{
		cpid = fork();

		if (cpid == -1)
		{
			printf("Fork failed\n");
			exit(1);
		}

		if (cpid == 0)
		{
			printf("Hello! I am child and my PID is:%ld\n", (long)getpid());
		}
		else
		{
			wait(NULL);
			wait(NULL);
			printf("Hello I am parent and my PID is:%ld\n", (long)getpid());
		}
	}

	return 0;
}
