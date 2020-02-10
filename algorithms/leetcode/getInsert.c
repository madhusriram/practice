#include <stdio.h>
#include <stdlib.h>

// https://leetcode.com/problems/search-insert-position/

int searchInsert(int *arr, int arr_len, int target) {
	int i;

	for (i = 0; i < arr_len; i++) {
		if (arr[i] == target)
			return i;
		if (arr[i] > target)
			return i;
	}

	return i;
}

int main() {
	int arr_len;

	printf("Enter array length: ");
	scanf("%d", &arr_len);

	int *arr;
	arr = malloc(sizeof(int) * arr_len);

	printf("Enter array values: ");
	int i = 0;
	for ( ; i < arr_len ; i++) {
		scanf("%d", &arr[i]);
	}

	int target;

	printf("Enter target to insert: ");
	scanf("%d", &target);

	int index = searchInsert(arr, arr_len, target);

	printf("Index at which %d can be inserted is %d\n", target, index);

	return 0;
}
