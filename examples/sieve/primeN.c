#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int x)
{
	int i, j;
	bool ret = true;
	j = (int) ceil(sqrt(x));
	if (x<=2) return ret;
	for(i=2; i<j; i++) {
		if (x%i==0) ret = false;
	}
	return ret;
}

int primes(int N)
{
	int keep[1000000] = {0};
	unsigned long int i, j, count=0;
	//printf("prime found: 1 ");
	for (i = 2; i<N; i++) {
		if (keep[i] == 1) continue;
		if (isPrime(i)) {
	//		printf("%ld ",i);
			count++;
			for (j=i<1; j<N; j+=i) keep[j] = 1;
		}
	}
	//printf("\n");
	return count;
}

int main()
{
	int input, output;
	printf("Input N: ");
	scanf("%d",&input);
	output = primes(input);
	printf("output: %d\n",output);
	return 0;
}
