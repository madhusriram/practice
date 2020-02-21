#include "isogram.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>

// Naive implementation uses O(n^2)
// Could be better with quick sort - O(nlogn)
// Could be done in O(1) space and O(N) time using a mask
bool is_isogram(const char *str) {
	int mask = 0;

	if (str == NULL)
		return false;
	if (strcmp(str, "") == 0) {
		return true;
	}
	
	int len = strlen(str);
	// iterate the string
	// if an alphabet is read and the
	// corresponding bit is already read before
	// return false 
	for (int i = 0; i < len; i++) {
		char c = tolower(str[i]);
		if (isalpha(c)) {
			if (mask & (1 << (c - 97)))
				return false;
			mask |= 1 << (c - 97);
		}
	}
	return true;
}
