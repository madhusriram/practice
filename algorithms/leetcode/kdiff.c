#include <stdio.h>
#include "sort.h"
#include <stdlib.h>

// https://leetcode.com/problems/k-diff-pairs-in-an-array/
// 3 1 4 1 5  k = 2 output = 2(1, 3 and 3, 5); sorted array: 1 1 3 4 5
// sort and use 2 pointers
int findCountOfDiffPairs(int *arr, int arr_len, int k) {
	heapsort(arr, arr_len, 'a');

	int l = 0;
	int r = 0;
	int count = 0;

	for ( ; r < arr_len; ) {
		if (arr[r] - arr[l] == k) {
			count++;
			r++;
			l++;
		} else if (arr[r] - arr[l] > k) {
			l++;
		} else {
			r++;
		}
	}
	return count;
}

int main() {
	int diff;
	int arr_len;
		
	printf("Enter the diff to be found: ");
	scanf("%d", &diff);

	printf("Enter array length: ");
	scanf("%d", &arr_len);

	int *arr = malloc(sizeof(int) * arr_len);

	int i;
	printf("Enter array: ");
	for (i = 0; i < arr_len; i++) {
		scanf("%d", &arr[i]);
	}
	arr[i] = '\0';

	int paircount = findCountOfDiffPairs(arr, arr_len, diff);

	printf("Pair count: %d\n", paircount);

	return 0;
}
