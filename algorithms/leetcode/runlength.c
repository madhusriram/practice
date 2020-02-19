#include <stdio.h>
#include <stdlib.h>

// Implement Run length encoding
// https://www.geeksforgeeks.org/run-length-encoding/

char *encode(char *str, int len) {
	// encoded string can be a max of len + len in case of no duplicates
	char *encodeStr = malloc(sizeof(char) * (len * 2 + 1));

	int count = 1;
	char *s1 = str;
	char *s2 = str + 1;
	int j = 0;

	for (int i = 0; i < len; i++) {
		if (*s1 == *s2) {
			count++;
		} else {
			encodeStr[j++] = *s1;
			encodeStr[j++] = 48 + count;
			s1 = s2;
			count = 1;
		}
		s2++;
	}
	encodeStr[j] = '\0';

	return encodeStr;
}

// returns the original string back
char *decode(char *str, int len) {
	char *decodeStr = malloc(sizeof(char) * (len / 2 + 1));

	char *s1 = str;
	char *s2 = str + 1;
	int j = 0;

	while (1) {
		int count = *s2 - 48;
		while (count > 0) {
			decodeStr[j++] = *s1;
			count--;
		}
		
		if (*(s1 + 2) != '\0') {
			s1 = s1 + 2;
			s2 = s2 + 2;
		} else {
			decodeStr[j] = '\0';
			return decodeStr;
		}
	}
}

int main() {
	int len;
	char *str;
	int i;

	printf("Enter string length: ");
	scanf("%d", &len);

	str = malloc(sizeof(char) * len);

	// read off the newline character after pressing <ENTER> on entering the
	// string length. This is because scanf() will read the newline character
	// as a character because of the %c format specifier
	getchar();

	printf("Enter string: ");
	for (i = 0; i < len; i++) {
		scanf("%c", &str[i]);
	}

	char *encodeStr = encode(str, len);
	printf("Encoded string: ");
	for (int i = 0; i < len * 2 + 1; i++) {
		if (encodeStr[i] == '\0')
			break;
		printf("%c", encodeStr[i]);
	}
	printf("\n");

	char *decodeStr = decode(encodeStr, (len * 2 + 1));

	printf("Decoded string: ");	
	for (int i = 0; i < len; i++) {
		if (decodeStr[i] != str[i]) {
			printf("Decoded string does not match at index: %d\n", i);
			break;
		}
		printf("%c", decodeStr[i]);
	}
	printf("\n");
	printf("SUCCESS: Encoded and Decoded string match!\n");
	return 0;
}

