#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

main()
{
	pid_t p;
	int i;
	p = fork();
	if ( p == 0 )
	{
		printf("Passou no wait = %d\n", wait(&i));
	}

	else
	if ( p > 0 )
	{
		printf("Passou no pai\n");
	}

	exit(0);	
}
	
