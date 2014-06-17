#include <stdio.h>
#include <math.h>

unsigned int Arr[10000];

int isOdd(unsigned int x) {
	printf("Got val: %d\n",x);
    if (x&0x1) return 1;
    else return 0;
}

int find(int x,int y)
{
    int ans;
	printf("Arr[x] is %d, x is %d, y is %d\n",Arr[x],x,y);
    if(x+1>y) return 1;
    ans = pow(Arr[x],find(x+1,y));
    return ans;
}

int main() {
    unsigned int N, Q, x, y, i;
    scanf("%d",&N);
    for (i=0; i<N; i++) {
        scanf("%d",&Arr[i]);
    }
    scanf("%d",&Q);
    for (i=0;i<Q;i++) {
        scanf("%d %d",&x, &y);
        if (isOdd(find(x-1,y))) printf("Odd\n");
        else printf("Even\n");
    }
    return 0;
}

