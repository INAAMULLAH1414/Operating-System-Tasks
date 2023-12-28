#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define SIZE 1024

int isPalindrome(char str[]);

int main()
{
	int fd1[2];
	int fd2[2];
	char buff[SIZE];
	memset(buff, '\0', SIZE);
	int rv1 = pipe(fd1);
	int rv2 = pipe(fd2);

	if (rv1 == -1 || rv2 == -1)
	{
		printf("\n Pipe failed");
		exit(1);
	}

	// create a child process
	pid_t cpid = fork();
	if (cpid == -1)
	{
		printf("\n Fork failed.");
		exit(1);
	}

	if (cpid == 0) // Child Process
	{
		close(fd1[1]);
		close(fd2[0]);
		char *msg;

		// Reading the string from parent
		int n = read(fd1[0], buff, SIZE);

		if (isPalindrome(buff) == 1)
		{
			msg = "Palindrome.\n";
		}
		else
		{
			msg = "Not Palindrome.\n";
		}

		// Sending the answer to parent
		write(fd2[1], msg, strlen(msg));
	}
	else // Parent Process
	{
		close(fd1[0]);
		close(fd2[1]);
		char a[1024];
		printf("Enter a string to check if it is a palindrome: ");
		fgets(a, 1024, stdin);

		// Sending the string to child
		write(fd1[1], a, strlen(a));

		// Reading the answer from child
		int n = read(fd2[0], buff, SIZE);
		write(1, buff, n);
		wait(NULL);
	}

	return 0;
}

// A function to check if a string str is palindrome
int isPalindrome(char str[])
{
	// Start from leftmost and rightmost corners of str
	int l = 0;
	int h = strlen(str) - 1;

	// Keep comparing characters while they are same
	while (h > l)
	{
		if (str[l++] != str[h--])
		{
			return 0;
		}
	}

	return 1;
}