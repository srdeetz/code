// C program to illustrate
// read system Call
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
	char c;
	int fd1 = open("sample.txt", O_RDONLY, 0);
	int fd2 = open("sample.txt", O_RDONLY, 0);
	read(fd1, &c, 1);
	read(fd1, &c, 1);
	read(fd1, &c, 1);
	// Moving the file pointer associated with fd1 by 3 positions
	printf("c = %c\n", c);
	exit(0);
}
