#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

int searchFirstOccurence(int *nums, int mid, int low, int target) {
	int first = mid;

	int high = mid - 1;
	while (low <= high) {
		if (nums[mid] == target) {
			first = mid;
			high = mid - 1;
		} else if (nums[mid] < target) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
		mid = (low + high) / 2;
	}
	return first;
}

int searchSecondOccurence(int *nums, int mid, int high, int target) {
	int second = mid;

	int low = mid + 1;
	while (low <= high) {
		if (nums[mid] == target) {
			second = mid;
			low = mid + 1;
		} else if (nums[mid] < target) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
		mid = (low + high) / 2;
	}
	return second;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int low = 0;
    int high = numsSize -1;
    int mid = high / 2;
    
    int *res = malloc(sizeof(int) * (*returnSize));
    int j = 0;
    
    // start becomes active when we find the first target value
    bool start = false;
	int first = -1;
	int second = -1;

    // with minor modification to binary search we can find the first and last
	// occurrence of an target in logn time	
    while (low <= high) {
		// found, now find the first and last occurrence
        if (nums[mid] == target) {
			// do binary search between low and mid
			first = searchFirstOccurence(nums, mid, low, target);
			// do binary search between mid and high
			second = searchSecondOccurence(nums, mid, high, target);
			break;
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
        mid = (low + high) / 2;
    }
    
    res[0] = first;
    res[1] = second;
    return res;
}

int main() {
	int arr[] = {5,7,7,8,8,10};
	int retsize = 2;
	int *res = searchRange(arr, 6, 8, &retsize);
	
	printf("[%d %d]\n", res[0], res[1]);

	return 0;
}
