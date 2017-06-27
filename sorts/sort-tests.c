#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define SMALL   20
#define MEDIUM  200
#define LARGE   5000
#define XL      50000

void test(uint32_t n, void(*sort)(uint32_t *, uint32_t));
void merge_sort(uint32_t *arr, uint32_t size);

int main()
{
	srand(time(NULL));
    printf("Test start\n");
    test(SMALL, merge_sort);
    printf("Test end\n");
    return 0;
}

void test(uint32_t n, void(*sort)(uint32_t *, uint32_t))
{
	uint32_t i;
	uint32_t arr[n];
    printf("--> TESTING %d RANDOM NUMBERS\n", n);
    for (i = 0; i<n; i++) {
    	arr[i] = rand();
    }
    sort(arr, n);
}

void merge_sort(uint32_t *arr, uint32_t size)
{
	uint32_t i;
	for (i = 0; i<size; i++) printf("arr[%d]: %d\n", i, arr[i]);
}