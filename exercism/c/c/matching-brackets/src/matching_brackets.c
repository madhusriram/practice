#include "matching_brackets.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

enum bracket {
	BOX = 1,
	FLOWER,
	PAREN
};

typedef struct node {
	char c;
	struct node *next;
} node_t;

node_t *list = NULL;

void pushNode(char c) {
	node_t *new = malloc(sizeof(node_t));
	new->c = c;
	new->next = list;
	list = new;
}

char peekStack() {
	if (list) {
		return list->c;
	}
	return 0;
}

void popStack() {
	if (! list)
		return;
	
	node_t *next = list->next;
	free(list);
	list = next;
}

void clearList() {
	while (list) {
		node_t *savenext = list->next;
		free(list);
		list = savenext;
	}
}

// convert bracket type to a custom int
int type(char c) {
	if (c == '(' || c == ')') {
		return PAREN;
	} else if (c == '{' || c == '}') {
		return FLOWER;
	} else if (c == '[' || c == ']') {
		return BOX;
	}
	return -1;
}

bool isStackEmpty() {
	if (! list)
		return true;

	return false;
}

bool is_paired(const char *input) {
	int len = strlen(input);

	for (int i = 0; i < len; i++) {
		if (input[i] == '(' || input[i] == '{' || input[i] == '[')
			pushNode(type(input[i]));
		if (input[i] == ')' || input[i] == '}' || input[i] == ']') {
			int opt = peekStack();
			switch (opt) {
				case BOX:
					if (input[i] != ']')
						return false;
					break;
				case PAREN:
					if (input[i] != ')')
						return false;
					break;
				case FLOWER:
					if (input[i] != '}')
						return false;
					break;
			}
			popStack();
		}
	}
	
	if (isStackEmpty())
		return true;

	return false;
}
