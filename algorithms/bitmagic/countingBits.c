#include <stdio.h>

// https://leetcode.com/problems/counting-bits/
// 2 [0,1,1]
// 5 [0,1,1,2,1,2]
// Space - O(n)
// Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
int *countBits(int num, int *returnSize) {
	int *res = malloc((num + 1) * sizeof(int));

	


	return res;
}

int main() {
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);

	int *res = countBits(n, &(n+1));

	for (int i = 0; i <= n; i++) {
		printf("%d ", res[i]); 
	}
	printf("\n");
	return 0;
}
