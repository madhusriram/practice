#include <stdio.h>

// https://leetcode.com/problems/reverse-integer/


int reverse(int n) {
	int tmp = 0;

	// 439
	while (n > 0) {
		tmp = tmp * 10 + n % 10;
		n = n / 10;
	}	
	return tmp;
}


int main() {
	int n;

	printf("Enter the number to reverse: ");
	scanf("%d", &n);

	int rev = reverse(n);

	printf("Reverse of %d is %d\n", n, rev);

}
