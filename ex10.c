#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

main()
{
	pid_t p;
	int i;
	
	for(i=0;i<50;i++)
	{
		p=fork();
		if ( p == 0 )
		{
			printf("Pid=%d PPid=%d\n",getpid(),getppid());
			break;
		}
	}

	if ( p>0)
		for(i=0;i<50;i++)
			wait(&i);

	exit(0);
}

