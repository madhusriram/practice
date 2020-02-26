#include <stdio.h>

// https://leetcode.com/problems/number-complement/
// Link math library - -lm

int findComplement(int num){
    int n = 1 << (int)log2(num);
    return (n | n - 1) - num;
}

int main() {
	int m;
	printf("Enter a number: ");
	scanf("%d", &m);

	printf("Complement of %d is %d\n", m, findComplement(m));
}
