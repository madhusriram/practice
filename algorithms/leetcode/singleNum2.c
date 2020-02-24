#include <stdio.h>
#include <stdlib.h>

// https://leetcode.com/problems/single-number-ii/
// should have linear time complexity and no extra space
int singleNumber(int *nums, int numSize) {
	int res = 0;


	return res;
}

//
// 2 2 3 2
// 
//
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
