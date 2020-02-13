#include <stdio.h>
#include <stdlib.h>

// https://leetcode.com/problems/median-of-two-sorted-arrays/
// Complexity should be O(log(m+n))
// [1, 3], [2] median = 2
// [1, 2], [3, 4] median = 2.5
double findMedian(int *arr1, int len1, int *arr2, int len2) {
	// merge 2 arrays

}

int main() {
	int len1;
	int len2;

	printf("Enter array 1 length: ");
	scanf("%d", &len1);

	printf("Enter array 2 length: ");
	scanf("%d", &len2);

	int *arr1 = malloc(sizeof(int) * len1);
	printf("Enter array1 values: ");
	for (int i = 0;i < len1; i++) {
		scanf("%d", &arr[i]);
	}
	
	int *arr2 = malloc(sizeof(int) * len2);
	printf("Enter array2 values: ");
	for (int i = 0;i < len2; i++) {
		scanf("%d", &arr[i]);
	}

	double median = findMedian(arr1, len1, arr2, len2);

	printf("Median of 2 sorted array is %2f\n", median);

	return 0;
}
