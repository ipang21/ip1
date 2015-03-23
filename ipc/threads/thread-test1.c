#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 12

void *thFn2(void *val) {
	int a = *(int *) val;
	printf("Hello from thread #%d!\n",a);
	usleep(50000); //some delay
	free(val);
	pthread_exit(NULL);
}

void *thFn() {
	char ret;
	printf("Hello from thread!\n");
}

int main() {
	pthread_t t1, t[NUM_THREADS];
	int ret, i, *arg;
	printf("Hello from main!\n");
	ret = pthread_create(&t1, NULL, thFn, NULL);
	if (ret) {
		printf("Error creating thread\n");
		return -1;
	}
	for (i=0; i<NUM_THREADS; i++) {
		arg = malloc(sizeof(int *));
		*arg = i;
		ret = pthread_create(&t[i], NULL, thFn2, (void *) arg);
		if (ret) {
			printf("Error opening thread #%d\n",i);
			return -1;
		}
	}
	//printf("Hello from main again!!\n");
	pthread_join(t1, NULL);
	for (i=0; i<NUM_THREADS; i++) pthread_join(t[i], NULL);
	printf("Hello from main again!!\n");
	return 0;
}
