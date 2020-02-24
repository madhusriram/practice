#include <stdio.h>
#include <limits.h>
#include <string.h>

#define LEN 1000

int firstUniqChar(char *s) {
	int letterMask[26] = {0};


	// have to traverse the whole string
	// repeating characters will have a -1 against it's key
	// non-repeating will have it's index stored
	for (int i = 0; s[i] != '\0'; i++) {
		int index = s[i] - 'a';
		if (letterMask[index] > 0 || letterMask[index] == -1) {
			letterMask[index] = -1;
		} else {
			letterMask[index] = i + 1;	// first time seeing this
		}
	}

	
	// find out the lowest index by traversing the mask
	// 0 -> non-existant, -1 - duplication, >0 means index of occurrence
	int min = INT_MAX;
	for (int i = 0; i < 26; i++) {
		if (letterMask[i] > 0) {
			min = (min > letterMask[i]) ? letterMask[i] : min;
		}
	}

	// becauses index'es are stored as i + 1 to avoid duplication with the meaning
	// of zero
	if (min == INT_MAX)
		return -1;

	return min - 1;
}

int main() {
	char s[LEN];

	printf("Enter string: ");
	for (int i = 0; i < LEN; i++) {
		scanf("%c", &s[i]);
		if (s[i] == '\n') {
			s[i] = '\0';
			break;
		}
	}

	int firstUniqIndex = firstUniqChar(s);
	printf("First unique character's index: %d\n", firstUniqIndex);

	return 0;
}
