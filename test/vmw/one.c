#include <stdio.h>
#include <stdlib.h>

int compareInt(const void *x, const void *y) {
    return *(int *)x - *(int *)y;
}

/*
 * Complete the function below.
 */
void partitionArray(int array_size, int* array) {
    qsort(array, array_size, sizeof(int),compareInt);

}

int main() {
	int arr[4] = {-1, 1, -1, 1};
	int i;
	for (i=0; i<4; i++) printf("%d ", arr[i]);
	printf("\n");
	partitionArray(4,arr);
	
	for (i=0; i<4; i++) printf("%d ", arr[i]);
	printf("\n");
	return;
}
