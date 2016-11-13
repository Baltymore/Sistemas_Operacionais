#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

main()
{
	pid_t p;
	int i;

	p=fork();
	if (p>0)
	{
		wait(&i);
	}
	else
	if (p==0)
	{
		for(i=2;i<=1000;i=i+2)
			printf("%d \n",i);
	}
	else
	if (p<0)
	{
		printf("Erro no fork");
	}
	
	exit(0);
}

