#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

main()
{
	int i;
	pid_t p1=0, p2=0;


	p1=fork();
	if (p1>0)
	{
		p2=fork();
		if ( p2 > 0 )
		{
			wait(&i);
			wait(&i);
		}
		else
		if ( p2==0)
		{
			for(i=1;i<=1000;i=i+2)
				printf("%d \n",i);
		}

	}
	else
	if (p1 == 0)
	{
		for(i=2;i<=1000;i=i+2)
			printf("%d \n",i);
	}
	
	if ( p1 < 0 || p2 < 0)
	{
		printf("Erro no fork\n");
	}

	exit(0);
 
}

