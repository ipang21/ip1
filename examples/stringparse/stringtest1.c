#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void test(char *x)
{
	int i = 0, current = 0, max =0;
	char maxChar, curChar = x[0];
	while (x[i] != '\0') {
		printf("x[%d] is %c\n",i,x[i]);
		if (x[i] == curChar) {
			current++;
			if (max < current) {
				max = current;
				maxChar = curChar;
			}
		}
		else {
			current = 1;
			curChar = x[i];
		}
		i++;
	}
	printf("output: ");
	for (i = 0; i<max; i++) printf("%c",maxChar);
	printf("\n");
}

int main()
{
	char tmp[100];
	printf("input: ");
	scanf("%[^\n]s", tmp);
	test(tmp);
	//printf("output: %s", tmp);
	return 0;
}