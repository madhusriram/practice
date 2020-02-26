#include <stdio.h>

// https://leetcode.com/problems/hamming-distance/
// Hamming distance is the number of bit positions 2 numbers are different
int hammingDistance(int x, int y) {
	return __builtin_popcount(x ^ y);	
}

int main() {
	int n;
	int m;

	printf("Enter number 1: ");
	scanf("%d", &n);

	printf("Enter number 2: ");
	scanf("%d", &m);

	printf("Distance between %d and %d is %d\n", m, n, hammingDistance(n, m));

	return 0;
}
