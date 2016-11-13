#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


int canal[5][2];
pid_t P[5];
pthread_t thread[50];
int sensor[5][10];

int vez=0;


void * thread_monitor(void *); void P1(void); void P2(void); void P3(void); void P4(void); void P5(void); void P6(void);

void main(void)
{
	int i,j;


	/* Cria Pipes*/
	for(i=0;i<5;i++)
	    pipe(canal[i]);
	
	/* Cria os processos Filhos */
	for(i=0;i<5;i++)
	{
	  P[i]=fork();
	  if (P[i] == 0 )
		break;
	}
	
	switch(i){
		case 0: P2(); break;
		case 1: P3(); break;
		case 2: P4(); break;
		case 3: P5(); break;
		case 4: P6(); break;
		case 5: P1(); /* Processo Pai */
	}
	exit(0);
				 
}		

void P1(void)
{
	int j, status, valores[5], soma;
	do{
		soma=0;
		for(j=0;j<5;j++)
		{
			read(canal[j][0],&valores[j],sizeof(int));
			soma=soma+valores[j];
		}
	}while(soma != 0);			

	for(j=0;j<5;j++) 
		kill(P[j],9);
	for(j=0;j<1;j++) 
		wait(&status);
	exit(0);
}

void P2(void)
{
	int j, cont=0, soma;

	do{
		soma=0;
		for(j=0;j<10;j++)
			pthread_create(&thread[j],NULL,thread_monitor,(void *)j);
		for(j=0;j<10;j++)
			pthread_join(thread[j],NULL);
	
		for(j=0;j<10;j++)
		{  
		 	soma=soma+sensor[0][j];
			sensor[0][j]=0;
		}
		write(canal[0][1],&soma,sizeof(int));
		
	}while(1);
	exit(0);	
}

void P3(void)
{
	int j, cont=0, soma, t;

	do{
		soma=0;
		for(j=10;j<20;j++)
			pthread_create(&thread[j],NULL,thread_monitor,(void*)j);
		for(j=10;j<20;j++)
			pthread_join(thread[j],NULL);
		for(j=0;j<10;j++)
		{  
		 	soma=soma+sensor[1][j];
			sensor[1][j]=0;
		}
		write(canal[1][1],&soma,sizeof(int));
		
	}while(1);
	exit(0);	
}

void P4(void)
{
	int j, cont=0, soma, t;

	do{
		soma=0;
		for(j=20;j<30;j++)
			pthread_create(&thread[j],NULL,thread_monitor,(void*)j);
		for(j=20;j<30;j++)
			pthread_join(thread[j],NULL);
		for(j=0;j<10;j++)
		{  
		 	soma=soma+sensor[2][j];
			sensor[2][j]=0;
		}
		write(canal[2][1],&soma,sizeof(int));

	}while(1);
	exit(0);	
}

void P5(void)
{
	int j, cont=0, soma, t;

	do{
		soma=0;
		for(j=30;j<40;j++)
			pthread_create(&thread[j],NULL,thread_monitor,(void*)j);
		for(j=30;j<40;j++)
			pthread_join(thread[j],NULL);
		for(j=0;j<10;j++)
		{  
		 	soma=soma+sensor[3][j];
			sensor[3][j]=0;
		}
		write(canal[3][1],&soma,sizeof(int));		
	}while(1);
	exit(0);		
}

void P6(void)
{
	int j, cont=0, soma, t;

	do{
		soma=0;
		for(j=40;j<50;j++)
			pthread_create(&thread[j],NULL,thread_monitor,(void*)j);
		for(j=40;j<50;j++)
			pthread_join(thread[j],NULL);
		for(j=0;j<10;j++)
		{  
		 	soma=soma+sensor[4][j];
			sensor[4][j]=0;
		}
		write(canal[4][1],&soma,sizeof(int));
	}while(1);
	exit(0);	
}


int read_com(int port){ int v; v=rand()%5; return v; }


void* thread_monitor(void *arg)
{
  int t, val;
  int P, T;	
  t=(int)arg;
  P=t/10;
  T=(t>9)?t%10:t;		
  /*do{*/
	  while(vez != T);
	  val=read_com(t+1);
	  sensor[P][T]=val;
   	  printf("Processo %d Thread %d Sensor[%d][%d]=%d Vez=%d\n",P,T,P,T,sensor[P][T],vez); fflush(stdout);
	  (vez==9)?vez=0:vez++;
  /*}while(val!=-1);*/
  pthread_exit(0);
}
    		
