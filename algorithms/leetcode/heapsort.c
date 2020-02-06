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
	char sorting_order;
	
	printf("Enter array length: ");
	scanf("%d", &actual_arr_len);

	// additional read for 'enter' key pressed after entering the array length
	scanf("%c", &sorting_order);

	while (1) {
		printf("Enter sorting order; 'a' for ascending and 'd' for descending: ");
		scanf("%c", &sorting_order);
		if (sorting_order == 'a' || sorting_order == 'd') {
			break;
		} else {
			printf("Invalid character, reenter!\n");
		}
	}

	printf("Enter data to be sorted: ");
	for (i = 0; i < actual_arr_len; i++) {
		scanf("%d", &arr[i]);
	}
	arr[i] = '\0';

	if (sorting_order == 'a') {
		heapsort(arr, actual_arr_len, sorting_order);
	} else {
		heapsort(arr, actual_arr_len, sorting_order);
	}

	// print array
	printarr(arr, actual_arr_len);

	return 0;
}
