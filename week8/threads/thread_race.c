/*
Example of race condition with two threads.
Note: To compile a C program with pthread.h in LINUX using GCC or G++, use the –lpthread option after the compile command.
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

pthread_t tid[2];
int order; // :(

void* place_order(void* arg)
{
	unsigned long i = 0;
	//mutex lock
	order += 1; // this is a shared variable on t1 and t2
	//mutex unlock


	printf("\n Order #%d received\n", order);

	// Wait for some time -- (delay)
	for (i = 0; i < (0xFFFFFFFF); i++);
		
	printf("\n Order #%d is ready\n", order);

	return NULL;

}

int main(void)
{
	int i = 0;
	int error;

	// Place orders for two customers
	while (i < 2) {
		// Create the threads
		error = pthread_create(&(tid[i]), NULL, &place_order, NULL);
		if (error != 0)
			printf("\nThread can't be created : [%s]", strerror(error));
		i++;
	}

	// Wait on both threads to finish
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);

	return 0;
}
