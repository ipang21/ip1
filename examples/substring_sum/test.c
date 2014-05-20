#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[2*100000+1], tmp[2*100000+1];
    int i, j, r, answer=0, val=0;
    scanf("%s",input);
    for (r=0; r<2*100000; r++)
        tmp[r] = '0';
    tmp[2*100000] = '\0';
    i=0;
    j=0;
    while(input[i] != '\0') {
		printf("input[%d] is %c\n",i,input[i]);
        while(input[i+j] != '\0') {
            tmp[j] = input[i+j];
            tmp[j+1] = '\0';
			val = atoi(tmp);
	    	printf("answer is %d\n", answer);
			printf("val is %d\n", val);
            answer+=val;
            j++;
        }
        for (r=0; r<2*100000; r++)
            tmp[r] = '0';
        j=0;
        i++;
    }
    printf("%d\n",answer);
}

