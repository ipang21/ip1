#include <stdio.h>
#include <math.h>

int getNumberOfPrimes(int N) {
    int i, j, count = 1;
    int keep[100];
    for (i=2; i<N; i++) {
		printf("keep[%d] is %d\n",i,keep[i]);
        if (keep[i] == 1) continue;
		printf("got here, i is %d\n",i);
        for (j=2; j<=i; j++){
			printf("i is %d, j is %d\n",i,j);
            if (j%i==0) break;
        }
        if (j==i) count++;
        for (j=i+i; j<N; j+=i)
            keep[j] = 1;
    }
    return count;
}

int getNumberOfPrimes2(int N) {
    int i, j,sqrtOfN, count = 0, err=0;
	int keep[100000];
    for (i=1; i<N; i++) {
	//printf ("i=%d\n",i);
		sqrtOfN = (int)ceil(sqrt(i));
        for (j=2; j<=sqrtOfN; j++) {
			//if (keep[j] == 0) continue;
            if (i%j==0) {
			err=1;
			}
        }
		
        if (err==0) {
			count++;
			keep[i] = 1;
		}
		else {
			keep[i] = 0;
			err = 0;
		}
    }
    return count;
}

int main()
{
	int i;
	//for (i = 0; i<100; i++)
		//printf("sqrt of %d is %d\n",i,(int)sqrt(i));
	printf("got: %d\n",getNumberOfPrimes(10));
	return 0;
}