#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

main()
{
	pid_t p1, p2, p3;
	int i;
	p1 = fork();
	if ( p1 > 0 )
	{
		p2 = fork();
		if ( p2 == 0 )
		{
			for(i=0;i<3;i++)
			{
				p3=fork();
				if ( p3 > 0 )
					break;
			}
		}
	}
	else
	if ( p1 == 0 )
	{ 	
		for(i=0;i<3;i++)
		{
			p3=fork();
			if ( p3 > 0 )
				break;
		}

	}
	getchar();
	exit(0);
}
