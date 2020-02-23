#include <stdio.h>
#include <stdlib.h>

// https://leetcode.com/problems/single-number/

// xor-logic works because there is always exactly one single number
// and other numbers appearing exactly twice
int singleNumber(int *nums, int numSize) {
	int res = 0;

	// traverse the arr
	// xor all the numbers, the last result would be the solo number
	for (int i = 0; i < numSize; i++) {
		res = res ^ nums[i];
	}

	return res;
}

/*
 * 1 0 0
 * 0 0 1
 * 0 1 0
 * 0 0 1
 * 0 1 0
 * -----
 * 1 0 0
 *
 * 0 1 0
 * 0 1 0
 * 0 0 1
 */
int main() {
	int len;
	int *arr;

	printf("Enter array length: ");
	scanf("%d", &len);

	arr = malloc(sizeof(int) * len);
	printf("Enter array: ");
	for (int i = 0; i < len; i++) {
		scanf("%d", &arr[i]);
	}

	int target = singleNumber(arr, len);
	printf("Result: %d\n", target);

	return 0;
}
