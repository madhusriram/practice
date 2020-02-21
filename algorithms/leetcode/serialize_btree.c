#include <stdio.h>
#include <stdlib.h>


struct node {
	int d;
	struct node *l;
	struct node *r;
};

struct node *createNode(int d) {
	struct node *new = malloc(sizeof(struct node));
	new->d = d;
	new->left = NULL;
	new->right = NULL;

	return new;
}

struct node *buildTree() {
	struct node *n = createNode(1);
	n->right = createNode(2);
	n->right->left = createNode(3);

	return n;
}

// encodes the tree to a malloc'ed string
char *serialize(struct node *tree) {
		
} 

int main() {
	struct node *tree = buildTree();

	serialize(tree);

	return 0;
}
