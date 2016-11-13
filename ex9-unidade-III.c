#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define N 5		/* Nr. de Filosofos */

void eat(int i)
{
  printf("Filosofo %d esta comendo...\n",i);	
  sleep( (rand()%5)+1 );
}

void think(int i)
{
  printf("Filosofo %d esta pensando...\n",i);
  sleep( (rand()%5)+1 );
}


void take_fork_left(int fi, int fo)
{
	/*printf("Filosofo %d Pega Garfo %d (Esquerda)\n",fi,fo);*/
}	

void take_fork_right(int fi, int fo)
{
	/*printf("Filosofo %d Pega Garfo %d (Direita)\n",fi,fo);*/
}	

void put_fork_left(int fi, int fo)
{
	/*printf("Filosofo %d Devolve Garfo %d (Esquerda)\n",fi,fo);*/
}	

void put_fork_right(int fi, int fo)
{
	/*printf("Filosofo %d Devolve Garfo %d (Direita)\n",fi,fo);*/
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
	for(i=0;i<N;i++)
		pthread_create(&phil[i],NULL, philosopher,(void*)i+1);

	getchar();

	exit(0);
}	

