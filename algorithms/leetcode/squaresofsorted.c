#include <stdio.h>
#include <limits.h>

// https://leetcode.com/problems/squares-of-a-sorted-array/
// Given an array of integers A sorted in non-decreasing(increasing) order, 
// return an array of the squares of each number, also in sorted non-decreasing order.

int ARRAY_LEN = 1000;

void printArray(int *arr, int arr_len) {
	printf("Squared and sorted array is: ");
	for (int i = 0; i < arr_len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int getSquare(int n) {
	return n * n;
}

void squareAndSort(int *arr, int *res_arr, int arr_len) {
	// if first element is non-negative then you could just square all
	// elements without getting in to the below logic
	if (arr && arr[0] >= 0) {
		// sort in place
		for (int i = 0; i < arr_len; i++) {
			arr[i] *= arr[i];
		}
		printArray(arr, arr_len);

		return;
	}

	int *nptr = arr;
	int *pptr = arr;
	int nlen = 0;

	// there are negatives in the array, get the last negative in arr
	// 0 is part of the positive array
	while (arr) {
		if (*arr < 0) {
			nptr = arr;
			nlen++;
		} else {
			pptr = arr;
			break;
		}
		arr++;
	}

	// move nptr <<---- and pptr ---->>
	int i = 0;
	int n1 = 0;
	int p2;
	int small;
	for ( ; *pptr != INT_MAX; i++) {
		small = 0; // reset on every call
		
		// only after the comparison can we tell which side pointers must be moved
		// the loop will be run until we exhaust the positive side of the array
		if (nlen > 0) {
			n1 = getSquare(*nptr);
			small = n1;
		} else {
			small = INT_MAX; // drive the loop to read in all of the positive values
		}

		p2 = getSquare(*pptr);

		if (small > p2) {	// positive side of the array is lesser
			small = p2;
			pptr++;
		} else if (nlen >= 0) {
			nlen--;
			nptr--;
		}

		res_arr[i] = small;
	}

	// take care of the negatives as positives are taken care of in the above loop
	for (; nlen != 0; nptr--, nlen--, i++) {
		res_arr[i] = getSquare(*nptr);
	}

	printArray(res_arr, arr_len);
}

int main() {
	int arr[ARRAY_LEN];
	int arr_len;
	int i;
	int res_arr[ARRAY_LEN];

	printf("Enter array length: ");
	scanf("%d", &arr_len);

	printf("Enter array: ");
	for (i = 0; i < arr_len; i++) {
		scanf("%d", &arr[i]);
	}
	// unique end of array to differentiate the 0 in an array
	arr[i] = INT_MAX;
	
	// method - 1 would be to go over the list elements squaring and
	// re-sorting them - O(nlogn) implementation, binary sort

	// method -2 would be to use 2 pointer logic
	// split negative and positive sides of the array
	// find the location of the first negative element inside the array
	// square it compare with the positive side, pick the smaller
	// if negative is smaller move the pointer, re-square and re-compare
	// 
	// -4 -2 1 5 6 7
	// 
	// negativePtr moves <<<----- starting from -2
	// positivePtr moves ----->>> starting from 1
	// O(n) time and O(n) space

	squareAndSort(arr, res_arr, arr_len);

	return 0;	
}