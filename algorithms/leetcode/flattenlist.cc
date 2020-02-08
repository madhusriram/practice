#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stack>

// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
// input : 1 2 3 4 5 6 -1 -1 -1 7 8 9 10 -1 -1 11 12
// output: 1 2 3 7 8 11 12 9 10 4 5 6

// input : 1 2 3 -1 -1 4 5 -1 -1 6
// output : 1 2 4 5 6 3
//
using namespace std;

const int LEN = 1000;

struct node *dList = nullptr;

struct node {
	int data;
	struct node *next;
	struct node *prev;
	struct node *child;
};

struct node *createNode(int n) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = n;
	newNode->next = nullptr;
	newNode->prev = nullptr;

	return newNode;
}

// when head pointer is passed in here the program should print the list
// in the order whichj printMultiLevelList() prints
void printList(struct node *l) {
	while (l != nullptr) {
		printf("%d ", l->data);
		l = l->next;
	}
	printf("\n");
}

// should be called once per level
int buildList(struct node *n, int *l) {
	int consumed = 0;

	while (*l && *l != INT_MAX && *l != -1) {
		struct node *newNode = createNode(*l);
		n->next = newNode;
		newNode->prev = n;
		n = n->next;
		
		consumed++;	
		// advance the input
		l = l + 1;
	}
	return consumed;
}

void buildDoublyLinkedList(int *list, int len) {
	int distanceFromHead = 0;
	struct node *start = nullptr;
	bool firstNode = true;
	int totalRead = 0;
	int *copy = list;

	// empty list
	if (*list == INT_MAX)
		return;

	if (firstNode) {			// no prev
		struct node *newNode = createNode(*list);
		start = dList = newNode;
		firstNode = false;
		totalRead++;	
		// advance the input
		list++;
	}

	struct node *tmp = dList;

	while (*list != INT_MAX) {
		int consumed = buildList(start, list);
		totalRead += consumed;
		list = copy + totalRead;

		// upon return from buildList() we might have reached  the end of the list
		if (*list == INT_MAX || totalRead > len)
			return;

		while (*list && *list == -1) {
			totalRead++;
			distanceFromHead++;
			list++;
		}

		// if there is evidence of child list move the start to the list point
		// where the child is expected to be
		for (start = tmp; distanceFromHead > 1; distanceFromHead--) {
			start = start->next;	
		}

		// create child tree to prepare writing the next level
		start->child = createNode(*list);
		start = start->child;
		tmp = start;
		distanceFromHead = 0;
		
		// list advancement helpers
		list++;
		totalRead++;
	}
}

// once flattened, printList() should print in the order what printMultiLevelList()
// prints
void flatten() {
	stack <struct node *> s;
	struct node *tmp = dList;
	struct node *cur = tmp;

	while (tmp) {
		if (tmp->child) {
			if (tmp->next)
				s.push(tmp->next);
			tmp->next = tmp->child;
			tmp->child->prev = tmp;
			tmp->child = nullptr;
			continue;
		}
	
		cur = tmp;
		tmp = tmp->next;

		if (! tmp) {
			if (! s.empty()) {
				tmp = s.top();
				cur->next = tmp;
				tmp->prev = cur;
				s.pop();
				continue;
			}
		}
	}
}

// given dList print multi level list
// in the order the program expects the list to be printed
void printMultiLevelList() {
	stack<struct node *> s;

	struct node *nextLevel;
	struct node *tmp = dList;
	s.push(dList);

	while (! s.empty()) {
		tmp = s.top();
		s.pop();
	
		while (tmp != nullptr) {
			printf("%d ", tmp->data);
			if (tmp->child) {
				if (tmp->next)
					s.push(tmp->next);
				tmp = tmp->child;
				continue;
			}
			tmp = tmp->next;
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
	int *list_elements = (int *)malloc(sizeof(int) * list_len);

	printf("Enter the list elements: ");
	for (i = 0; i < list_len; i++) {
		scanf("%d", &list_elements[i]);
	}

	list_elements[i] = INT_MAX;

	buildDoublyLinkedList(list_elements, list_len);

	// for debug!
	//printMultiLevelList();

	flatten();

	// should print the same as what printMultiLevelList() prints before flattening
	printf("Flat list: ");
	printList(dList);

	return 0;
}
