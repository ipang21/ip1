#include <stdio.h>
#define TEST_SIZE 14
int test[TEST_SIZE] = {8, 9, 0, 4, 2, 10, 23, 182, 21, 231, 29, 55, 12, 33};
int sorted[TEST_SIZE] = {0};

void swap(int *array, int index1, int index2)
{
	int temp = array[index1];
	array[index1] = array[index2];
	array[index2] = temp;
}

void sort(int *array, int start, int end)
{
	int i, j, left, mid, right;
	if (start<end) {
		left = start;
		mid = (start+end) /2;
		right = mid+1;
		sort(array, start, mid);
		sort(array, mid+1, end);
		i = left;
		while(left<=mid && right<=end) {
			//printf("comparing array[left]=%d, array[right]=%d, left=%d, mid=%d, right=%d; start=%d, end=%d\n",array[left], array[right], left, mid, right,start,end);
			if (array[left] <= array[right]) {
				sorted[i] = array[left];
				//printf("left: Got position %d, value %d\n",i, sorted[i]);
				left++;
			}
			else {
				sorted[i] = array[right];
				//printf("right: Got position %d, value %d\n",i, sorted[i]);
				right++;
			}
			i++;
		}
		for (j = 0; j<=mid-left;j++) {
			sorted[i+j] = array[left+j];
		}
		for (j = 0; j<=end-right;j++) {
			sorted[i+j] = array[right+j];
		}
		printf("sorted so far: ");
		for (i = start; i<=end; i++) {
			array[i] = sorted[i];
			printf("%d ",sorted[i]);
		}
		printf("\n");
	}
}

void mergesort(int *x)
{
	sort(x,0,TEST_SIZE-1);
}

int main()
{
	int i;
	printf("Sorting array: ");
	for (i = 0; i<TEST_SIZE; i++) {
		printf("%d ", test[i]);
	}
	printf("\n");
	mergesort(test);
	
	printf("Sorted array: ");
	for (i = 0; i<TEST_SIZE; i++) {
		printf("%d ", sorted[i]);
	}
	printf("\n");
	return 0;
	
}