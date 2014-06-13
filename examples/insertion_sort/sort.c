#include <stdio.h>

#define MAX_NUM_ITEMS 1000

int arr[MAX_NUM_ITEMS];

void insertion_sort(int num) {
	int i, j;
	int temp;
	for (i=1; i<num; i++) {
		temp = arr[i];
		for (j=i-1; j>=0; j--) {
			if (arr[j] > temp) {
				arr[j+1] = arr[j];
			}
			else {
				break;
			}
		}
		arr[j+1] = temp;
	}
}

int main() {
	int i, n;
	printf("Number of items to sort: ");
	scanf("%d",&n);
	if (n>MAX_NUM_ITEMS) {
		printf("Too many items\n");
		return 1;
	}
	printf("Items: ");
	for (i=0; i<n; i++) {
		scanf("%d",&arr[i]);
	}
	printf("Got array: ");
	for (i=0; i<n; i++) {
		printf("%d ",arr[i]);
	}
	printf("\n");
	insertion_sort(n);
	printf("Array after sort: ");
	for (i=0; i<n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
