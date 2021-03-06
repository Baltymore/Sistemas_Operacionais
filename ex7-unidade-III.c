#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int canal_1[2], canal_2[2], i, val;

void * thread_t2(void *arg)
{
	
	int i, val;
	/* Envio de valores pares de P2 para P3 */	
	for(i=0;i<=100;i=i+2)
		write(canal_1[1], &i, sizeof(int));
	close(canal_1[1]);

	/* Leitura dos valores impares enviados por P3 */	
	for(i=0;i<50;i++){
		read(canal_2[0], &val, sizeof(int));
		printf("%d ",val);
	}
	close(canal_2[0]);
	pthread_exit(0);
}
	
        
void * thread_t3(void *arg)
{

	int i, val;
	/* Leitura de valore pares enviados por P2 */
	for(i=0;i<=50;i++){
		read(canal_1[0], &val, sizeof(int));
		printf("%d ",val);
	}
	close(canal_1[0]);

	/* Envio de valores impares de P3 para P2 */	
	for(i=1;i<100;i=i+2)
		write(canal_2[1], &i, sizeof(int));
	close(canal_2[1]);
	pthread_exit(0);
}

main()
{
        pthread_t t2, t3;

        if ( pipe(canal_1) < 0 ){ printf("Erro na criacao do pipe 1\n"); exit(-1);}
        if ( pipe(canal_2) < 0 ){ printf("Erro na criacao do pipe 2\n"); exit(-1);}

	pthread_create(&t2,NULL,thread_t2,NULL);
	pthread_create(&t3,NULL,thread_t3,NULL);

	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	
	exit(0);
}
	
 

