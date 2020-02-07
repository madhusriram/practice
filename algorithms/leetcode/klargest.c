#include <stdio.h>
#include "sort.h"

const int ARRAY_LEN  = 1000;

void method1(int *arr, int arr_len, int k) {
	heapsort(arr, arr_len, 'd');

	for (int i = 0; i < arr_len; i++) {
		printf("%d ",arr[i]);
	}	
	printf("\n");

	for (int i = 0; arr[i] != '\0'; i++) {
		if (i + 1 == k) {
			printf("%dth largest element is %d\n", k, arr[i]);
			return;
		}
	}

	printf("%dth largest element not found\n", k);
}


int main() {
	int arr[ARRAY_LEN];
	int arr_len;
	int k;
	int i;

	printf("Enter array length: ");
	scanf("%d", &arr_len);

	printf("Enter unsorted array: ");
	for (i = 0; i < arr_len; i++) {
		scanf("%d", &arr[i]);
	}	
	arr[i] = '\0';

	printf("Enter 'K': ");
	scanf("%d", &k);


	// method-1
	// sort using min-heap
	// traverse until 'k' is reached
	// O(nlogn + k)	
	method1(arr, arr_len, k);

	// method-2
	// build max-heap
	// call extractMax() k times
	// O(Klogn)

	return 0;
}
