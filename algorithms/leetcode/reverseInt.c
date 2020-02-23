#include <stdio.h>

// https://leetcode.com/problems/reverse-integer/


int reverse(int n) {
	int rev = 0;

	bool neg = false;
	if (n < 0) {
		neg = true;
		n = -1 * n;
	}
	// 439
	while (n > 0) {
		rev = rev * 10 + n % 10;
		n = n / 10;
	}

	// restore sign
	if (neg) {
		rev = -1 * rev;
	}	
	return rev;
}


int main() {
	int n;

	printf("Enter the number to reverse: ");
	scanf("%d", &n);

	int rev = reverse(n);

	printf("Reverse of %d is %d\n", n, rev);

}
