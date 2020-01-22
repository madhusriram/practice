// Class defining a Binary Search Tree, balanced and unbalanced

#ifndef _BST_H_
#define	_BST_H_

#include <iostream>
#include <list>

template <typename T>
struct Node {
	T data;
	Node<T> *left;
	Node<T> *right;
	Node<T> *next; 		// used only for 1 leetcode problem

	static Node<T> *createNode(T d) {
		Node<T> *n = new(Node<T>);
		n->data = d;
		n->left = nullptr;
		n->right = nullptr;
		n->next = nullptr;

		return n;
	}
};

template <typename T>
class Tree {
public:
	Node<T> *root = nullptr;

	T getVal(Node<T> *);

	// level order tree traversal
	void levelOrder(std::list<T> &);

	// recusive in order tree traversal
	void printInOrder(std::list<T> &);

	// TODO without recursion in order tree traversal
	void printInOrderWithoutRecursion(std::list<T> &);

	// TODO build binary tree with an array as input
	void buildTree(const T *arr);

	// No recursion but replicate call-stack with a stack
	void printInOrderWithStack(std::list<T> &);

	// post order tree traversal using recursion
	void printPostOrder(std::list<T> &);

	// connect each node to its right node
	void connectToNext();

	// print next connected complete binary tree
	void printNextTree();

	unsigned int getLength();


private:
	void recurseInOrder(std::list<T>&, Node<T>* );
	void recursePostOrder(std::list<T>&, Node<T>* );
};

// Unbalanced tree
template <typename T>
class BST : public Tree<T> {
	public:
		// insert to the tree
		void insert(T );
	
	private:
		void insert(T , Node<T> *);

		void insertLeft(T, Node<T> *);

		void insertRight(T, Node<T> *);


};

// AVL tree
template <typename T>
class AVL : public Tree<T> {
	public:
		void insert(T );

};

// RED BLACK tree
template <typename T>
class RBT : public Tree<T> {
	public:
		void insert(T );
};

#include "bst_impl.hh"

#endif
