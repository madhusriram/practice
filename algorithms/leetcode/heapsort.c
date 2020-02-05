#include <stdio.h>
#include "sort.h"

// Heap sort

const int ARRAY_LEN = 1000;

void printarr(int *arr, int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	int arr[ARRAY_LEN];
	int actual_arr_len;
	int i, j;

	printf("Enter array length: ");
	scanf("%d", &actual_arr_len);

	printf("Enter data to be sorted in ascending order: ");
	for (i = 0; i < actual_arr_len; i++) {
		scanf("%d", &arr[i]);
	}
	arr[i] = '\0';

	buildMaxHeap(arr, actual_arr_len);
	heapsort(arr, actual_arr_len);

	// print array
	printarr(arr, actual_arr_len);

	return 0;
}
