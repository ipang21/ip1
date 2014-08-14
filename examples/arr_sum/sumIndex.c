#include <stdio.h>
#include <stdlib.h>

int main() {
    int i,j;
    int sum, left, right;
    unsigned int T, N;
    unsigned int A[100000];
    scanf("%d", &T);
    for (i=0; i<T; i++) {
        scanf("%d", &N);
        for (j=0; j<N; j++){
            scanf("%d", &A[j]);
        }
        if (N==1) {
            printf("YES\n");
            continue;
        }
        else {
            left = 0;
            right = N - 1;
            if (A[left] < A[right]) {
				sum = A[right];
				right--;
			}
            else {
				sum = 0 - A[left];
				left++;
			}
            while (left != right) {
				printf("sum is %d\n", sum);
                if (sum < 0) {
                    sum += A[right];
                    right--;
                }
                else if (sum > 0) {
                    sum -= A[left];
                    left++;
                }
            }
			printf("final sum is %d\n",sum);
            if (sum == 0) printf("YES\n");
            else printf("NO\n");
        }
    }
}

