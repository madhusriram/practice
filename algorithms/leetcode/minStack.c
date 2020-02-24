#include <stdio.h>
#include <stdlib.h>

// https://leetcode.com/problems/min-stack

struct node {
	int data;
	struct node *next;
	struct node *minNode;
};

typedef struct {
	struct node *stack;
} MinStack;


/** initialize your data structure here. */
void createNode(int x, struct node **head) {
	struct node *new = malloc(sizeof(struct node));
	new->data = x;
	new->next = NULL;
	
	if (*head) {
		if ((*head)->minNode->data > x)
			new->minNode = new;
		else 
			new->minNode = (*head)->minNode;
	} else {
		new->minNode = new;
	}
	
	// update head of the stack
	new->next = *head; 
	*head = new;
}

MinStack* minStackCreate() {
	MinStack *obj = malloc(sizeof(MinStack));

	return obj;
}

void minStackPush(MinStack* obj, int x) {
	if (! obj)
		return;

	createNode(x, &obj->stack);
}

void minStackPop(MinStack* obj) {
	if (! obj)
		return;

	if (obj->stack) {
		struct node *savenewHead = obj->stack->next;
		free(obj->stack);
		obj->stack = savenewHead;
	}
}

int minStackTop(MinStack* obj) {
	if (! obj)
		return -1;

	if (obj->stack) {
		return obj->stack->data;
	}
	return -1;
}

int minStackGetMin(MinStack* obj) {
	if (! obj)
		return -1;

	if (obj->stack) {
		return obj->stack->minNode->data;
	}
}

void minStackFree(MinStack* obj) {
	if (! obj)
		return;

	for (struct node *s = obj->stack; s != NULL; ) {
		struct node *save = s->next;
		free(s);
		s = save;
	}
	free(obj);
}

int main() {
	MinStack *obj = minStackCreate();
	minStackPush(obj, -2);
	minStackPush(obj, 0);
	minStackPush(obj, -3);
	printf("%d \n",minStackGetMin(obj));
	minStackPop(obj);
	printf("%d \n", minStackTop(obj));
	printf("%d \n",minStackGetMin(obj));
	minStackFree(obj);
	return 0;
}

//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin();   --> Returns -3.
//minStack.pop();
//minStack.top();      --> Returns 0.
//minStack.getMin();   --> Returns -2.
