#include "word_count.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

// getWord returns a malloc'ed string
// returns NULL if no valid token was available
char *getWord(const char *text, int *offset) {
	int tokenId = *offset;
	int start = *offset;

	for (; text[tokenId] != '\0'; tokenId++) {
		if (text[tokenId] == ' ' || text[tokenId] == ',')
			break;
	}

	// end of a string reached
	if (tokenId == start) {
		return NULL;
	}

	// malloc a string
	char *word = malloc((tokenId - start) * sizeof(char));
	
	// normalize the word
	int j = 0;
	for (int i = 0; i < tokenId - start; i++, j++) {
		if (isalpha(text[i + start])) {
			word[j] = tolower(text[i + start]);
		} else {
			word[j] = text[i + start];
		}
	}
	word[tokenId - start] = '\0';

	if (text[tokenId] != '\0')
		tokenId++;

	*offset = tokenId;

//	printf("Word: %s\n", word);
	return word;
}

// returns the count of words in the string
int word_count(const char *text, word_count_word_t *words) {
	
	char *word;
	int wc = 0; // count of unique words
	int offset = 0;

	// extract tokens from text until the end is reached
	while ((word = getWord(text, &offset)) != NULL) {
		size_t l = strlen(word);
		if (l > MAX_WORD_LENGTH) {
			return EXCESSIVE_LENGTH_WORD;
		}	
		
		// search in words to find the string
		for (int i = 0; i < MAX_WORDS; i++) {
			// if not found
			if (words[i].count == 0) {
				memcpy(words[i].text, word, l);
				words[i].count = 1;
				wc++;
				break;
			}

			// if already exists
			if (strncmp(words[i].text, word, MAX_WORD_LENGTH) == 0) {
				if (l == strlen(words[i].text)) {
					words[i].count++;
					break;
				}
			}
		}
	}

	if (wc > MAX_WORDS) {
		return EXCESSIVE_NUMBER_OF_WORDS;
	}

	return wc;	
}
