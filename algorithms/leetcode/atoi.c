#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>
#include <stdint.h>

// https://leetcode.com/problems/string-to-integer-atoi/

#define LEN 1000

// "42" -> 42
// "    -42" -> -42
// "4193   with words" -> 4193
// "words with 987" -> 0
// First character should be either a whitespace or a number to perform a conversion
// "-91283472332" -> -2147483648
int atoi(char *str) {
	bool negative = false;
	int32_t num = 0;

	while (*str != '\0') {
		if (*str == ' ') {
			str++;
			continue;
		}

		if (isalpha(*str))
			return num;
		
		// if there is a minus or positive sign but no number after that return 0
		if (*str == '-' || *str == '+' || isdigit(*str)) {
			if ((*str == '-' || *str == '+') && (*(str + 1) == '\0' || ! isdigit(*(str + 1))))
				return num;
			// get the sign
			switch (*str) {
			case '-':
				negative = true;
				str++;
				break;
			case '+':
				str++;
				break;
			}
			// it's digits right now!
			while (*str != '\0') {
				num = num * 10 + (*str - 48);
				str++;
					
				if (! isdigit(*str))
					return num;
				if (negative) {
					if (-1 * num >= INT_MIN)
						return INT_MIN;
				}
				if (num >= INT_MAX)
					return INT_MAX;
			}
		}
		str++;
	}
	
	// if negative number
	if (negative)
		num = -1 * num;

	return num;
}

int main() {
	char str[LEN];
	int i;

	printf("Enter the string: ");
	for (i = 0; i < LEN; i++) {
		scanf("%c", &str[i]);
		if (str[i] == '\n')
			break;
	}
	str[i] = '\0';

	int32_t res = atoi(str);
	printf("String: \"%s\" converted to integer is: %d\n", str, res);

	return 0;
}
