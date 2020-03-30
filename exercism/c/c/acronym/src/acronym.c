#include "acronym.h"

#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

char *abbreviate(const char *phrase) {
	if (! phrase || strcmp(phrase, "") == 0)
		return NULL;
	
	int len = strlen(phrase);
	bool readWord = false;
	char *res = (char *)malloc(len * sizeof(char));
	int j = 0;

	// iterate the array
	for (int i = 0; i < len; i++) {
		if (!readWord && isalpha(phrase[i])) {
			readWord = true;
			if (! isupper(phrase[i]))
				res[j] = phrase[i] - 32;
			else
				res[j] = phrase[i];
			j++;
		}
		if (phrase[i] == '-' || isspace(phrase[i]))
			readWord = false;
	}
	res[j] = '\0';

	return res;
}
