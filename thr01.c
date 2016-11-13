#include <pthread.h>
#include <stdio.h>


void* thr_par(void *p)
{
	int i;
	for(i=2;i<=10000;i=i+2)
		printf("%d \n",i);
	pthread_exit(0);
}


void* thr_impar(void *p)
{
	int i;
	for(i=1;i<=10000;i=i+2)
		printf("%d \n",i);
	pthread_exit(0);
}


main(){
	pthread_t par, impar;

	pthread_create(&par, NULL, thr_par, NULL);	
	pthread_create(&impar, NULL, thr_impar, NULL);


	pthread_join(par,NULL);
	pthread_join(impar,NULL);
}
 
