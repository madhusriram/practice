#include <stdio.h>
#include "sort.h"

// https://leetcode.com/problems/two-sum/

int ARRAY_LEN = 1000;

// calculate two sum using 2 pointers
void twoSum(int *arr, int len, int target_sum) {

	int i = 0, j = len - 1;

	while (i != j) {
		int res = arr[i] + arr[j];

		if (res == target_sum) {
			printf("There are 2 integers which add up to the sum and the indexes in the sorted array are: ");
			printf("[%d %d]\n", i, j);	
			break;
		}

		if (res > target_sum) {
			j--;
		} else {
			i++;
		}
	}
}

void printarray(int *arr, int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
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

	// sort array
	buildMaxHeap(array, array_len);
	heapsort(array, array_len);
	printf("Sorted array: ");
	printarray(array, array_len);
	
	twoSum(array, array_len, target_sum);

    return 0;
}
