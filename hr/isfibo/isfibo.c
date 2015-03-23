#include <stdio.h>
#include <math.h>

int checkSqrt(unsigned long long x) {
    unsigned long long tmp, tmp2;
	printf("got x = %llu\n", x);
    if (x <= 0) return 0;
    tmp = (unsigned long long) (sqrt(x)+0.5);
    tmp2 = (unsigned long long) (sqrt(x));
    if (( (tmp*tmp) == x) || ( (tmp2*tmp2) == x))
        return 1;
    else
        return 0;
}

void solve(unsigned long long val) {
	unsigned long long a1, a2, temp;
	unsigned long long s0, s1, s2, s3;
	a1 = val & 0xFFFFFFFF;
	a2 = val >> 32;
	s0 = a1 * a1;
	
	printf("val^2 is %llu\n", temp);
	printf("5*val*val is %llu\n", 5*temp);
    if (val <= 0) printf("IsNotFibo\n");
    else if (checkSqrt((5*val*val)+4) || checkSqrt((5*val*val)-4))
        printf("IsFibo\n");
    else
        printf("IsNotFibo\n");
}

int main() {
    unsigned long long i, num, tests;
    scanf("%llu",&tests);
    for (i=0; i<tests; i++) {
        scanf("%llu", &num);
        solve(num);
    }
    return 0;
}
