#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

main()
{
	pid_t p;
	int s, r;
	p = fork();
	if ( p == 0 )
	{
		execve("./prog_exec",NULL,NULL);
		printf("A chamada exec falhou\n");
	}
	else
	if ( p > 0 )
	{
		wait(&s);
		printf("Wait() no Pai finalizado\n");
		getchar();
	}
	exit(0);
}
		
		

	
