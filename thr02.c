#include <pthread.h>
#include <stdio.h>


void* thread(void *p)
{
	int *x,i;
	x=(int*)p;
	if ( *x == 0 )
		for(i=2;i<=10000;i=i+2)
			printf("%d \n",i);
	else
	if ( *x == 1 )
		for(i=1;i<10000;i=i+2)
			printf("%d \n",i);
	pthread_exit(0);
}


main(){
	pthread_t par, impar;

	int x=0,y=1;

	pthread_create(&par, NULL, thread,(void*)&x);	
	pthread_create(&impar, NULL, thread,(void*)&y);


	pthread_join(par,NULL);
	pthread_join(impar,NULL);
}
 
