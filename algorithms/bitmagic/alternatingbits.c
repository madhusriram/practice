#include <stdio.h>
#include <stdbool.h>

// Check if a number has alternating bits
// Meaning if two adjacent bits are different bits
// 101 - 5 - this 101 | 010 == 111
// 110 - 6
// 111 - 7
// 1000 - 8
// 1001 - 9
// 1010 - 10 - this
// 1011 - 11
// 1100 - 12
// 1101 - 13
// 1110 - 14
// 1111 - 15
// 10000 - 16
// 10001 - 17
// 10010 - 18
// 10011 - 19
// 10100 - 20
// 10101 - 21 - this
bool isAlternating(int n) {
	unsigned int allBitsSet = n ^ (n >> 1);
	
	if ((allBitsSet & (allBitsSet + 1)) == 0)
		return true;

	return false;
}

int main() {
	int n;
	printf("Enter number: ");
	scanf("%d", &n);

	bool res = isAlternating(n);
	if (res) 
		printf("%d has alternating bits\n", n);
	else
		printf("%d does not have alternating bits\n", n);

	return 0;
}
