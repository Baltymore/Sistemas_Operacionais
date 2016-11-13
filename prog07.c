#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

main()
{
	pid_t p;
	unsigned long int i=0;
	for(;;)
	{
		p = fork();
		if ( p == 0 )
		{	
		    exit(0);
		}
		else
		if ( p < 0 )
		{
			printf("Fork falhou na iteracao %d\n",i);
			getchar();
			break;
		}
		i++;
	}
	exit(0);
}	
		
