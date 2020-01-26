#include <stdio.h>

#define CHAR_LEN 1000

int main() {
	char s[CHAR_LEN];

	fgets(s, CHAR_LEN, stdin);

	printf("%s", s[0]);
	
	return 0;	
}
