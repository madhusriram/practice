#include <stdio.h>
#include <stdlib.h>

// Leetcode: https://leetcode.com/problems/palindrome-number/
// 121 != -121
// do it without using strings

int main() {
	int n;
	printf("Enter a number to check if it's a palindrome: ");
	scanf("%d", &n);


	// create another number and then verify if it's the same as the input
	int rev = 0;
	// negative numbers cannot be a palindrome
	if (n < 0) {
		printf("Number: %d is not a palindrome\n", n);
		exit(0);
	}

	int tmp = n;

	while (tmp > 0) {
		rev = rev * 10 + tmp % 10;
		tmp = tmp / 10;
	}

	if (rev == n) {
		printf("Number: %d is a palindrome\n", n);
	} else {
		printf("Number: %d is not a palindrome\n", n);
	}

	return 0;
}
