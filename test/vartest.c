#include <stdio.h>

int main() {
	int a = 1;
	int b = 2;
	int c = 3;
	a = b = c;
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("c = %d\n", c);
	return 0;
}
