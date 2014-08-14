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

void printer(char *st)
{
	printf("printer: %s\n",st);
}

int main()
{
	char tmp[10][10*10*10*10];
	printf("input: ");
	scanf("%s", tmp[1]);
	scanf("%s", tmp[2]);
	//test(tmp);
	printer(tmp[1]);
	printer(tmp[2]);
	//printf("output: %s\n", tmp[1]);
	//printf("output: %s\n", tmp[2]);
	return 0;
}