#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

main()
{
	pid_t p;
	int s;
	printf("Meu Pid = %d\n", getpid());
	p = fork(); 
	if ( p > 0 )
	{
		printf("Eu sou o processo Pai e meu filho e' o processo PID=%d\n",p);
		wait(&s); /* bloqueia o pai ate' o termino do filho */
		printf("Processo filho terminou\n");
	
	}
	else
	if ( p == 0 )
	{
		printf("Eu sou o processo PID=%d, filho do processo PID=%d\n",getpid(),getppid());
		sleep(5); /* bloqueia o filho por 5 segundos */
	}
	exit(0);
}
