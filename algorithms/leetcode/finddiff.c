#include <stdio.h>

// https://leetcode.com/problems/find-the-difference

#define LEN 1000

char findTheDifference(char *s, char *t) {
	int s1 = 0;
	int s2 = 0;

	// traverse second string until the end
	// calculating the sum of both strings.
	// At the end subtract both numbers and find the added character
	for (int i = 0; t[i] != '\0'; i++) {
  		if (s[i] != '\0') {
			s1 += s[i] - 'a';
		}
		s2 += t[i] - 'a';
	}
	return s2 - s1 + 'a';
}

int main() {
	char s1[LEN];
	char s2[LEN];

	int i;
	printf("Enter string 1: ");
	for (i = 0; i < LEN; i++) {
		scanf("%c", &s1[i]);
		if (s1[i] == '\n') {
			s1[i] = '\0';
			break;
		}
	}
	printf("Enter string 2: ");
	for (i = 0; i < LEN; i++) {
		scanf("%c", &s2[i]);
		if (s2[i] == '\n') {
			s2[i] = '\0';
			break;
		}
	}

	char addedChar = findTheDifference(s1, s2);
	printf("Added character: %c\n", addedChar);

	return 0;
}
