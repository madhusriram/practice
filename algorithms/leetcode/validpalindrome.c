#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// https://leetcode.com/problems/valid-palindrome/

#define	MAX_LEN 1000

bool isAlphaNumeric(char c) {
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= 0 && c <= 9))
		return true;
	return false;
}

// A man, a plan, a canal: Panama
// while iteration consider only alphanumeric characters
bool checkPalindrome(char *buf, int len) {
	// empty string is a palindrome
	if (! buf)
		return true;

	char *f = buf;			// move to the right
	char *s = buf + len - 1;	// move to the left

	// run the loop until both pointers meet
	while (f != s) {
		if(! isAlphaNumeric(*f)) {
			f++;
			continue;
		}
		if (! isAlphaNumeric(*s)) {
			s--;
			continue;
		}
		
		// both are valid, do a check
		if (tolower(*f) != tolower(*s))
			return false;

		f++;
		s--;
	}
	return true;
}	

int main() {
	char buf[MAX_LEN];

	printf("Enter the string: ");

	fgets(buf, MAX_LEN, stdin);

	// fgets() adds the new-line, remove it
	// this assumes that the input string is not longer than MAX_LEN
	// and '\n' is always present.
	buf[strlen(buf)-1] = '\0';
	
	bool res = checkPalindrome(buf, strlen(buf));

	if (res)
		printf("\"%s\" is a palindrome\n", buf);
	else
		printf("\"%s\" is  not a palindrome\n", buf);
	return 0;
}
