#include <stdio.h>

// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/\

int numberOfSteps (int num){
    int count = 0;
    
    while (num != 0) {
        if (num & 1) {
            num = num ^ 1;
         } else {
            num >>= 1;
        }
        count++;
    }
    
    return count;
}

int main() {
	int n;
	printf("Enter number: ");
	scanf("%d", &n);

	printf("Steps to zero: %d\n", numberOfSteps(n));

	return 0;
}
