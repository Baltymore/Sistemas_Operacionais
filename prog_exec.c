#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

main()
{
	pid_t p;
	int i;
	for(i=0;i<10;i++)
		printf("Prog_exec = %d\n",i);
	
	p=fork();
	getchar();
	exit(0);
}
