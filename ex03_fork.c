#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

/* Em outro terminal, enquanto o processo Filho "dorme" por 1 minuto, verifique os processos: pai e filho.
 # ps -U seu_login -u seu_login u -H
*/

int main()
{
	pid_t pid;
	int status;
	
	pid=fork();

	if (pid == 0 )
	{
		printf("Processo Filho: PID=%d\n", getpid());
		sleep(60);
		printf("Processo Filho terminou\n");
	}
	else
	if ( pid > 0 )
	{
		printf("Processo Pai: PID=%d\n", getpid());
		printf("Processo Pai terminou\n");
		
	}
	exit(1);
}

