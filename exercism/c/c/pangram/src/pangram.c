#include "pangram.h"

#include <ctype.h>

bool is_pangram(const char *sentence) {
	if (! sentence)
		return false;
	
	int mask = 0;

	for (int i = 0; sentence[i] != '\0'; i++) {
		char c = sentence[i];

		if (!isalpha(c))
			continue;
		if (isupper(c))
			c += 32;
		
		mask |= (1 << (c - 97));
	}

	// check at the end if 26 bits are set.
	for (int i = 0; i < 26; i++) {
		if ((mask & (1 << i)) == 0)
			return false;
	}

	return true;
}
