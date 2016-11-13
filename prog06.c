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
	if ( p > 0 )
	{
		getchar();
	}
	exit(0);
}

