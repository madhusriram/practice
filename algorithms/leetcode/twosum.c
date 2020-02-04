#include <stdio.h>

// https://leetcode.com/problems/two-sum/

int ARRAY_LEN = 1000;

// print the 2 indices of the array if its sum matches target_sum
// else prints -1
void twoSum(int *arr, int target_sum) {
	int i = 0;
	int j = 0;

	if (! arr) {
		printf("-1");
		return;
	}

	// naive implementaion - O(N^2)
	for ( ; arr[i] != '\0'; i++) {
		for (j = i + 1; arr[j] != '\0'; j++) {
			if (arr[i] + arr[j] == target_sum) {
				printf("[%d %d]\n", i, j);
			}	
		}
	}

	if (i == 0 && j == 0) {
		printf("-1");
		return;
	}
}

int main() {
	int target_sum;
	int array_len;
	int array[ARRAY_LEN];

	printf("Enter array length: ");
	scanf("%d", &array_len);

	printf("Enter array of ints: ");
	int i = 0;
	for (; i < array_len; i++) {
		scanf("%d", &array[i]);
	}
	array[i] = '\0';

	printf("Enter target sum to find in the array: ");
	scanf("%d", &target_sum);

	twoSum(array, target_sum);

	return 0;
}
