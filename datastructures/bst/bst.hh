// Class defining a Binary Search Tree, balanced and unbalanced

#ifndef _BST_H_
#define	_BST_H_

#include <iostream>

template <typename T>
struct Node {
	T data;
	Node<T> *left;
	Node<T> *right;

	static Node<T> *createNode(T d) {
		Node<T> *n = new(Node<T>);
		n->data = d;
		n->left = nullptr;
		n->right = nullptr;
	}
};

template <typename T>
class Tree {
public:
	void printInOrder();

	void printPostOrder();

	void printPreOrder();
};

// Unbalanced tree
template <typename T>
class BST : public Tree {
	public:
		// root node
		struct Node<T> *root = nullptr;

		// insert to the tree
		void insert(T );
};

// AVL tree
template <typename T>
class AVL : public Tree {


};

// RED BLACK tree
template <typename T>
class RBT : public Tree {


};

#include "bst.cc"

#endif
