#include <stdio.h>
#include <stdlib.h>

// https://leetcode.com/problems/single-number-iii/
// should have linear time complexity and no extra space
// https://www.geeksforgeeks.org/find-the-two-numbers-with-odd-occurences-in-an-unsorted-array/
int *singleNumber(int *nums, int numSize, int returnSize) {
	int *arr = malloc(sizeof(int) * returnSize);
	int xor = 0;
	
	// xor will cancel out all the duplicate numbers
	// the residue xor will be the xor of 2 non dup numbers, xor = a ^ b
	for (int i = 0; i < numSize; i++) {
		xor ^= nums[i];		
	}

	// now that we have the xor find another number in the array that would
	// contribute to the xor
	// find the rightmost set bit in the xor logic
	int mask = xor & ~(xor - 1);
	int n1 = 0;
	int n2 = 0;

	for (int i = 0; i < numSize; i++) {
		if (nums[i] & mask)
			n1 ^= nums[i];
		else
			n2 ^= nums[i];
	}	
	arr[0] = n1;
	arr[1] = n2;

	return arr;
}

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

	int *res= singleNumber(arr, len, 2);
	printf("Result: %d %d\n", res[0], res[1]);

	return 0;
}
