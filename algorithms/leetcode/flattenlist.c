#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

const int LEN = 1000;

struct node *dList = NULL;

struct node {
	int data;
	struct node *next;
	struct node *prev;
	struct node *child;
};

struct node *createNode(int n) {
	struct node *new = malloc(sizeof(struct node));
	new->data = n;
	new->next = NULL;
	new->prev = NULL;

	return new;
}

void printList(struct node *l) {
	while (l != NULL) {
		printf("%d ", l->data);
		l = l->next;
	}
	printf("\n");
}

// should be called once per level
void buildList(struct node *n, int **list) {
	int *l = *list;
	
	while (*l && *l != INT_MAX && *l != -1) {
		struct node *new = createNode(*l);
		n->next = new;
		new->prev = n;
		n = n->next;
		
		// advance the input
		l = l + 1;
	}
}

void buildDoublyLinkedList(int *list, int len) {
	int distanceFromHead = 0;
	struct node *start = NULL;
	bool firstNode = true;

	// empty list
	if (*list == INT_MAX)
		return;

	if (firstNode) {			// no prev
		struct node *new = createNode(*list);
		start = dList = new;
		firstNode = false;
		
		// advance the input
		list++;
	}

	struct node *tmp = dList;

	while (*list != INT_MAX) {
		buildList(start, &list);
		
		while (*list && *list == -1) {
			distanceFromHead++;
			list++;
		}
		printf("Distance from head: %d\n", distanceFromHead);

		// if there is evidence of child list move the start to the list point
		// where the child is expected to be
		for (start = tmp; distanceFromHead > 1; distanceFromHead--) {
			printf("%d ", start->data);
			start = start->next;	
		}
		printf("\n");

		// create child tree to prepare writing the next level
		start->child = createNode(*list);
		start = start->child;
		tmp = start;
		distanceFromHead = 0;

		list++;
	}
}

void flatten() {

}

// give dList print multi level list
void printMultiLevelList() {
	struct node *nextLevel;
	struct node *tmp = dList;

	while (tmp) {
		if (tmp->child) {
			nextLevel = tmp->child;
			printf("CHILD: %d\n", nextLevel->data);
		}
		printf("%d ", tmp->data);
		tmp = tmp->next;
		if (! tmp) {
			tmp = nextLevel;
			nextLevel = NULL;
		}
	}
	printf("\n");
}

// -1 in the input indicates the null for us!
// [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
// [1 2 3 4 5 6 -1 -1 -1 7 8 9 10 -1 -1 11 12]
int main() {
	int list_len;
	int i;

	printf("Enter the total elements count: ");
	scanf("%d", &list_len);
	int list_elements[LEN];

	printf("Enter the list elements: ");
	for (i = 0; i < list_len; i++) {
		scanf("%d", &list_elements[i]);
	}
	list_elements[i] = INT_MAX;

	buildDoublyLinkedList(list_elements, list_len);

	//printMultiLevelList();

	return 0;
}
