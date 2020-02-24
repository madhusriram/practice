#include "word_count.h"
#include <string.h>
#include <stdlib.h>

// returns the count of words in the string
int word_count(const char *text, word_count_word_t *words) {
	
	char *word;
	int wc = 0;
	int index = 0;

	word_count_word_t *words = malloc(sizeof(word_count_word_t) * MAX_WORDS);
	memset(words, 0, sizeof(word_count_word_t) * MAX_WORDS);

	while ((word = strtok(text, " ")) != NULL) {
		int len = strlen(word);
		if (len > MAX_WORD_LENGTH) {
			return EXCESSIVE_LENGTH_WORD;
		}	
		wc++;
		
		// search in words to find the string
		words[i]					
	}

	if (wc > MAX_WORDS) {
		return EXCESSIVE_NUMBER_OF_WORDS;
	}

	return wc;	
}
