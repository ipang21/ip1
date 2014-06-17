#include <stdio.h>
#include <stdlib.h>

void copy2(int **ptr, int val) {
	*(*ptr) = val;
}

void copyVal(void **ptr, int value) {
	int *tmp;
	*ptr = malloc(sizeof(int));
	tmp = *ptr;
	*tmp = value;
//	*(int*)(*ptr) = value;
}

int main() {
	int *x;
	void *y;
	int *z = (int *) malloc(sizeof(int));
	int value;
	printf("value: \n");
	scanf("%d",&value);
	copyVal(&y,value);
	//y = malloc(sizeof(int));
	//*(int *) y = value;
	*x = value;
	copy2(&z,value);
	printf("*x is %d\n",*x);
	printf("*y is %d\n",*(int *)y);
	printf("*z is %d\n", *z);
	free(y);
	free(z);
}
