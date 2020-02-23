#include <stdio.h>
#include <stdlib.h>

// https://leetcode.com/problems/missing-number/
//
// 1 2 3 4 5
// sorting and traversing could be done with O(nlogn) and no extra space
int missingNumber(int* nums, int numsSize) {
	int total = numsSize * (numsSize + 1)/2;

	for (int i = 0; i < numsSize; i++) {
		total -= nums[i];
	}
	return total;
}

int main() {
	int len;
	int *arr;

	printf("Enter array size: ");
	scanf("%d", &len);

	arr = malloc(sizeof(int) * len);
	printf("Enter array: ");
	for (int i = 0; i < len; i++) {
		scanf("%d", &arr[i]);
	}

	int result = missingNumber(arr, len);
	printf("Missing number: %d\n", result);

	return 0;
}
