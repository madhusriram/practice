#include "word_count.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

// returns the count of words in the string
int word_count(const char *text, word_count_word_t *words) {
	
	char *word;
	int wc = 0;

	words = malloc(sizeof(word_count_word_t) * MAX_WORDS);
	memset(words, 0, sizeof(word_count_word_t) * MAX_WORDS);

	while ((word = strtok((char *)text, " ")) != NULL) {
		size_t len = strlen(word);
		if (len > MAX_WORD_LENGTH) {
			return EXCESSIVE_LENGTH_WORD;
		}	
		wc++;
		
		// search in words to find the string
		word_count_word_t *tmp = words;
		while (true) {
			printf("%d \n", tmp->count);
			// if not found
			if (tmp->count == 0) {
				memcpy(tmp->text, word, len);
				tmp->count = 1;
				break;
			}

			// if already exists
			if (strncmp(tmp->text, word, MAX_WORD_LENGTH)) {
				if (len == strlen(tmp->text)) {
					tmp->count++;
					break;
				}
			}

			// not found, yet!
			tmp++;
		}
		wc++;
	}

	if (wc > MAX_WORDS) {
		return EXCESSIVE_NUMBER_OF_WORDS;
	}

	return wc;	
}
