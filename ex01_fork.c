#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main()
{
	pid_t pid, tmp;
	int status;
	
	pid=fork();

	if ( pid == 0 )
	{
		printf("Processo Filho: PID=%d\n", getpid());
		sleep(5);
	}
	else
	if ( pid > 0 )
	{
		printf("Processo Pai: PID=%d\n", getpid());
		tmp=wait(&status);
		printf("Processo Filho (%d) terminou\n", tmp);
		printf("Processo Pai terminou\n");	
	}
	exit(1);
}

