// C program to illustrate
// read system Call
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
	char letter;
	int fd1 = open("sample.txt", O_RDONLY, 0);
	int fd2 = open("sample.txt", O_RDONLY, 0);
<<<<<<< HEAD
	read(fd1, &c, 1);
	read(fd1, &c, 1);
	read(fd1, &c, 1);
	// Moving the file pointer associated with fd1 by 3 positions
	printf("c = %c\n", c);
=======
	read(fd1, &letter, 1);
	read(fd1, &letter, 1);
	read(fd1, &letter, 1);
	// Move the file pointer associated with fd1 by 3 position
	printf("letter = %c\n", letter);
>>>>>>> f67ccb5e10132d6b2a0049fd21189bd8146c9eb8
	exit(0);
}
