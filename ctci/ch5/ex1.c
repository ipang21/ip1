#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void printBin(uint32_t x)
{
	int count = 31;
	while ( (x&(1<<count)) == 0) count--;
	while (count >=0) {
		printf("%c", (char) 48 + ((x&(1<<count))>>count));
		count--;
	}
}

uint32_t insertBin(uint32_t base, uint32_t val, int start, int end)
{
	uint32_t mask = 0xFFFFFFFF;
	mask &= ~((1 << start+1) - (1 << end));
	return (base & mask) + (val << end);
}

int main()
{
	char number[256];
	char insert[256];
	uint32_t num=0, ins=0, result;
	int i, j;
	int count=0;
	printf("Enter value for the base number: ");
	scanf("%s", number);
	printf("Enter value for the insert number: ");
	scanf("%s", insert);
	printf("Enter value for i: ");
	scanf("%d", &i);
	printf("Enter value for j: ");
	scanf("%d", &j);

	while(number[count] != '\0') {
		num <<= 1;
		num = num + ((int)number[count] - 48);
		count++;
	}
	count=0;
	while(insert[count] != '\0') {
		ins <<= 1;
		ins = ins + ((int)insert[count] - 48);
		count++;
	}
	printf("Input:\tN=%s,\tM=%s,\ti=%d,\tj=%d\n",number,insert,i,j);
	printf("Numbers converted: \tN=%d,\tM=%d\n",num,ins);
	result = insertBin(num,ins,j,i);
	printf("result is: ");
	printBin(result);
	printf("\n");
	return 0;
}
