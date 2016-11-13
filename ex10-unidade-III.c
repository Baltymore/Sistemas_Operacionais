#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>


#define TRUE 1
#define N 5		/* Nr. de Filosofos */

sem_t semaphore[6]; /* A posicao zero nao eh usada */

void eat(int i)
{
  printf("Filosofo %d esta comendo...\n",i); fflush(stdout);	
  sleep( (rand()%5)+1 );
}

void think(int i)
{
  printf("Filosofo %d esta pensando...\n",i); fflush(stdout);
  sleep( (rand()%2)+1 );
}


void take_fork_left(int fi, int fo)
{
	sem_wait(&semaphore[fo]);
	printf("Filosofo %d Pega Garfo %d (Esquerda)\n",fi,fo); fflush(stdout);
}	

void take_fork_right(int fi, int fo)
{
	sem_wait(&semaphore[fo]);
	printf("Filosofo %d Pega Garfo %d (Direita)\n",fi,fo); fflush(stdout);
}	

void put_fork_left(int fi, int fo)
{
	sem_post(&semaphore[fo]);
	printf("Filosofo %d Devolve Garfo %d (Esquerda)\n",fi,fo); fflush(stdout);
}	

void put_fork_right(int fi, int fo)
{
	sem_post(&semaphore[fo]);
	printf("Filosofo %d Devolve Garfo %d (Direita)\n",fi,fo); fflush(stdout);
}	


void philosopher(void *i)
{
	int f=(int)i;
	while(TRUE)
	{
		think(f);
		take_fork_left(f, (f==1)?5:f-1);
		take_fork_right(f, f);
		eat(f);
		put_fork_left( f, (f==1)?5:f-1);
		put_fork_right(f, f);
	}
}

main()
{
	int i;
	pthread_t phil[N];

	for(i=0;i<5;i++)
		sem_init(&semaphore[i],0,1);

	for(i=0;i<N;i++)
		pthread_create(&phil[i],NULL, philosopher,(void*)i+1);

	getchar();

	exit(0);
}	

