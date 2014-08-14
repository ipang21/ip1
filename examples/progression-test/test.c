#include <stdio.h>

int main()
{
	int i, num, set[256];
    int diff1 = 0, diff_prev = 0, count=0, found=0, diff_save, diff;
	printf("input: ");
	scanf("%d", &num);
	printf("got: %d\n",num);
	for (i = 0; i<num; i++)
		scanf("%d", &set[i]);
	for (i = 0; i<num; i++)
		printf("set[%d] is %d\n",i,set[i]);
		
    for (i = 0; i<num-1; i++) {
        diff1 = set[i+1] - set[i];
        if (diff_prev == 0) diff_prev=diff1;
        else if (diff_prev != diff1) {
            if (found == 0) count = i;
            found++;
			diff_save = diff_prev;
            diff_prev=diff1;
        }
    }
	printf("diff_prev is %d, diff_save is %d, count is %d\n",diff_prev, diff_save, count);
    if (found>1) {diff = diff_prev;}
	else {
		if (count == 1) { count--; diff = diff_prev; }
		else diff = diff_save;
	}
    printf("%d", set[count]+diff);
	return 0;
}