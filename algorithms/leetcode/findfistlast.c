#include <stdio.h>
#include <stdlib.h>

// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

// binary search
// 5 7 7 8 8 10
int search(int *arr, int arr_len, int target) {
	int low = 0;
	int high = arr_len;
	int mid = 0;

	while (low <= high) {
		mid = (low + high)/2;
		if (arr[mid] == target) {
			return mid;
		} else if (arr[mid] < target) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return -1;
}

// improved implementation O(log(N))
int *searchRangeLogn(int *arr, int arr_len, int target) {
	int *index = malloc(sizeof(int) * 2);
	index[0] = -1;
	index[1] = -1;

	// perform binary search to find the element
	int pos = search(arr, arr_len, target);
	if (pos == -1) {
		return index;
	}
	
	index[0] = pos;
	while (pos < arr_len) {
		if (arr[pos] > target) {
			break;
		}
		pos++;
	}
	index[1] = pos - 1;
	return index;
}

// initial implementation O(n)
int *searchRange(int *arr, int arr_len, int target) {
	int *index = malloc(sizeof(int) * 2);
	index[0] = -1;
	index[1] = -1;

	for (int i = 0; i < arr_len; i++) {
		if (arr[i] == target) {
			index[0] = i;
			while (i < arr_len) {
				if (arr[i] > target) {
					index[1] = i - 1;
					return index;
				}
				i++;
			}
			index[1] = i;
			return index;
		}
	}
	return index;
}

int main() {
	int target;
	
	printf("Enter target to search: ");
	scanf("%d", &target);

	int arr_len;
	printf("Enter array length: ");
	scanf("%d", &arr_len);

	int *arr = malloc(sizeof(int) * arr_len);
	int i;
	printf("Enter array: ");
	for (i = 0; i < arr_len; i++) {
		scanf("%d", &arr[i]);
	}

	//int *index = searchRange(arr, arr_len, target);
	int *index = searchRangeLogn(arr, arr_len, target);

	printf("%d %d\n", index[0], index[1]);

	return 0;
}
