/**
 C program to illustrate I/O system Calls
**/
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main (void)
{
	int fd[2];
	char buf1[12] = "hello world";
	char buf2[12];

	// assume foobar.txt is already created
	fd[0] = open("today.txt", O_RDWR); // file descriptor 1
	fd[1] = open("today.txt", O_RDWR); // file descriptor 2
	
	// Write 12 Bytes in the file today - starting from the cursor at position 0
	write(fd[0], buf1, strlen(buf1));		

	// Write to the STDOUT the value read from the file today.txt (fd[0])
	//write(1, buf2, read(fd[0], buf2, 12));
	write(1, buf2, read(fd[1], buf2, 12));

	close(fd[1]);

	return 0;
}


/*
CASE 1:

fd 0:
	-
	-
> 	-
	-	 moved 12 Bytes in the file


fd 1
> 	-
	-
	-
	-   moved by 0

<<<<<<< HEAD
fd 0:
	-
	-
	-
>	-   moved 12 Bytes in the file

fd 1
>	-
	-
	-
	-   moved by 0

lseek allows to move file pointer associated with a file descriptor
=======
lseek allows to move a file pointer associated with a file descriptor
>>>>>>> f67ccb5e10132d6b2a0049fd21189bd8146c9eb8
*/