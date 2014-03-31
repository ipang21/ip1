#include <stdio.h>
#include <stdlib.h>

int reverse(char *str)
{
	int i = 0;
	int length;
	char tmp;
	while(str[i] != '\0') i++;
	length = i-1;
	for (i = 0; i<length/2; i++) {
		tmp = str[i];
		str[i] = str[length-1-i];
		str[length-1-i] = tmp;
	}
	return 0;
}

int main()
{
	char string[256];
	int ret;
	printf("Input string: ");
	fgets(string, 256, stdin);
	printf("Got input: %s\n",string);
	ret = reverse(string);
	if (ret == 0)
		printf("Reversed string: %s\n", string);
	return 0;
}