#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>

#define TRUE 1
#define N 5		/* Nr. de Filosofos */
#define LEFT (i+N-1)%N	/* Nr. do Filosofo 'a Esquerda do Filosofo i */
#define RIGHT (i+1)%N	/* Nr. do Filosofo 'a Direita do Filosofo i */
#define THINKING 0	/* Filosofo esta pensando */
#define HUNGRY 1	/* Filosofo esta tentando pegar garfos */
#define EATING 2	/* Filosofo esta comendo */

int state[N]={0,0,0,0,0};
sem_t mutex, s[N]; 

void eat(int i)
{
  sleep( (rand()%1)+1 );
}

void think(int i)
{
  sleep( (rand()%1)+1 );
}


void test(int i)
{
	if (state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING)
	{
		state[i] = EATING;
		printf("Filosofo %d COMENDO ...\n",i); fflush(stdout);
		sem_post(&s[i]);
	}
}

void take_forks(int i)
{
	sem_wait(&mutex);
		state[i] = HUNGRY;
		test(i);
	sem_post(&mutex);
	sem_wait(&s[i]);
}
		
void put_forks(int i)
{
	sem_wait(&mutex);
		state[i] = THINKING;
		printf("Filosofo %d TERMINOU DE COMER...\n",i); fflush(stdout);
		test(LEFT);
		test(RIGHT);
	sem_post(&mutex);
}



void philosopher(void *x)
{
	int f=(int)x;
	while(TRUE)
	{
		think(f);
		take_forks(f);
		eat(f);
		put_forks(f);

	}
}

main()
{

	int j,i;
	pthread_t phil[N];

/*	for(j=0,i=0;j<N;j++,i=j)
	{
		printf("F=%d LEFT=%d RIGHT=%d\n",i,LEFT,RIGHT);
	}
	
	*/
	sem_init(&mutex, 0, 1);
	for(j=0;j<N;j++)
		sem_init(&s[j],0,0); /* Importante, deve inicializar com zero e nao hum */

	for(j=0;j<N;j++)
		pthread_create(&phil[j],NULL, philosopher,(void*)j);
	getchar();

	sem_destroy(&mutex);
	for(j=0;j<N;j++)
		sem_destroy(&s[j]);
	exit(0);
}	

