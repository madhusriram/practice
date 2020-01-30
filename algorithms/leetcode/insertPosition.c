#include <stdio.h>

// https://leetcode.com/problems/search-insert-position/


int main() {
	const int arr[] = {1, 3, 5, 6, 7};
	
	int target;
	printf("Enter the element to find: ");
	scanf("%d", &target);

	int target_index = -1;
	int len = sizeof(arr)/sizeof(arr[0]);
	int cur;
	int prev_index = -1;

	for (cur = 0; cur < len; cur++) {
		if (arr[cur] == target) {
			target_index = cur;
			break;
		}
		if (prev_index != -1) {
			if (target > arr[prev_index] && target < arr[cur]) {
				target_index = cur;
				break;
			}
		}

		prev_index = cur;	
	}

	if (target_index == -1)
		target_index = cur;

	printf("Index: %d\n", target_index);

	return 0;
}
