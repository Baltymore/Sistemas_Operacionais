#include <pthread.h>
#include <stdio.h>

int counter=0;

void * thread1(void *p)
{
  long int i;
  for(i=0;i<10000000;i++)
	printf("Thread 1 \n");
  pthread_exit(0);
}



void * thread2(void *p)
{
  long int i;
  for(i=0;i<10000000;i++)
	printf("Thread 2 \n");
  pthread_exit(0);
}


void * thread3(void *p)
{
  long int i;
  for(i=0;i<10000000;i++)
	printf("Thread 3 \n");
  pthread_exit(0);
}




main()
{
	pthread_t t1, t2, t3;
	
	pthread_create(&t1,NULL,thread1,NULL);
	pthread_create(&t2,NULL,thread2,NULL);
	pthread_create(&t3,NULL,thread3,NULL);
	
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	
}


