#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

/* Em outro terminal, enquanto os processos Filhos "dormem" por 4 minutos, verifique os processos: pai e filhos.
   # ps -U seu_login -u seu_login u -H
*/

int main()
{
	pid_t pid[2];
	printf("Processo Pai PID=%d\n", getpid());
	pid[0]=fork();
	if (pid[0] == 0 )
	{
		printf("Processo Filho: PID=%d\n", getpid());
		pid[1]=fork();
		if ( pid[1] == 0 )
		{
			printf("Processo Filho: PID=%d\n", getpid());
			sleep(240);
			printf("Processo Filho: PID=%d Terminou\n", getpid());
			exit(1);
		}
		else
		if ( pid[1] > 0 )
		{
			sleep(240);
			printf("Processo Filho: PID=%d Terminou\n", getpid());
			exit(1);
		}
	}		
	getchar();
	printf("Processo Pai terminou\n");
	exit(1);
}

