#include "armstrong_numbers.h"
#include <stdio.h>
#include <math.h>

int is_armstrong_number(int num) {
	int digits = 0;
	int stepCount = 0;

	for (int i = 1; num >= stepCount; i = i * 10) {
		digits++;
		stepCount = 10 * i;
	}

	// 154 -> 1^3 + 5^3 + 4^3
	// 5 -> 5^1
	int res = 0;
	int n = num;
	while (n > 0) {
		int r = n % 10;
		n = n / 10;
		res += pow(r,digits);
	}

	if (res == num) {
		return 1;
	}

	return 0;
}
