#include <stdio.h>

int max_sum(int *vector, int len)
{
    int best = 0, current = 0;
    int i = 0;
    for(i = 0; i < len; ++i)
    {
        current += *(vector + i);
        if(current < 0)
        {
            current = 0;
        }
        best = best > current ? best : current;
		printf("vector = %d, current = %d, best = %d\n",*(vector + i), current, best);
    }
    return best;
}

int main()
{
	int a[] = {1,3,-1,-1,7,-3,2};
	printf("best is %d\n",max_sum(a,7));
	return 0;
}