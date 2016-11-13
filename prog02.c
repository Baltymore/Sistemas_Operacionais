#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

main()
{
	pid_t p;
	int i;
	for(i=0;i<6;i++)
	{
		p=fork();
		if ( p == 0 )
			break;
	}
	
	getchar();
	exit(0);
}
