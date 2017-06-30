#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define SMALL   20
#define MEDIUM  200
#define LARGE   5000
#define XL      50000

#define TEST_RAND_MAX 20000

uint32_t mytest[20] = { 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

void test(uint32_t n, void(*sort)(uint32_t *, uint32_t));
void check(uint32_t *arr, uint32_t size);
void merge_sort(uint32_t *arr, uint32_t size);

int main()
{
    srand(time(NULL));
    printf("Test start\n");
    test(SMALL, merge_sort);
    test(MEDIUM, merge_sort);
    test(LARGE, merge_sort);
    test(XL, merge_sort);
    printf("Test end\n");
    return 0;
}

void test(uint32_t n, void(*sort)(uint32_t *, uint32_t))
{
    uint32_t i;
    uint32_t arr[n];
    printf("--> TESTING %d RANDOM NUMBERS\n", n);
    for (i = 0; i<n; i++) {
        arr[i] = rand() % TEST_RAND_MAX;
    }
    sort(arr, n);
    check(arr, n);
}

void check(uint32_t *arr, uint32_t size)
{
    uint32_t i, prev = arr[0];
    uint32_t passed = 1;
    for (i = 0; i<size; i++) {
        if (arr[i] < prev) {
            printf("*** CHECK ERROR *** i = %d, arr[i] = %d, prev = %d\n", i, arr[i], prev);
            passed = 0;
            break;
        }
        prev = arr[i];
    }
    if (passed) printf("CHECK PASSED!!\n");
    else {
        for (i = 0; i<size; i++) printf("arr[%d]: %d\n", i, arr[i]);
    }
}

void merge_sort(uint32_t *arr, uint32_t size)
{
    uint32_t i, j, k;
    uint32_t merge_size, merge_idx;
    uint32_t start, mid, end;
    uint32_t tmp[size];
    printf("MERGE SORT\n");
    //for (i = 0; i<size; i++) printf("arr[%d]: %d\n", i, arr[i]);
    for (merge_size = 2; merge_size/2 <= size; merge_size *= 2) {
        //printf("merge_size = %d\n", merge_size);
        for (merge_idx = 0; merge_idx < size; merge_idx += merge_size) {
            start = merge_idx;
            end = (merge_idx + merge_size > size)? size-1 : merge_idx + merge_size - 1;
            mid = (merge_idx + merge_size > size)? merge_idx + merge_size/2 - 1 : (start+end) / 2 ;
            if (mid >= size) continue;
            i = start;
            j = mid + 1;
            //printf("start = %d, mid = %d, end = %d\n", start, mid , end);
            while ((start <= mid) && (j <= end)) {
                if (arr[start] < arr[j]) {
                    tmp[i] = arr[start];
                    start++;
                    i++;
                }
                else {
                    tmp[i] = arr[j];
                    j++;
                    i++;
                }
            }
            while (start <= mid) {
                tmp[i] = arr[start];
                start++;
                i++;
            }
            while (j <= end) {
                tmp[i] = arr[j];
                j++;
                i++;
            }
            for (i = merge_idx; i<=end; i++) arr[i] = tmp[i];
        }
        //for (i = 0; i<size; i++) printf("tmp[%d]: %d\n", i, tmp[i]);
    }
    
    //for (i = 0; i<size; i++) printf("tmp[%d]: %d\n", i, tmp[i]);
}