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

	static Node<T> *createNode(T d) {
		Node<T> *n = new(Node<T>);
		n->data = d;
		n->left = nullptr;
		n->right = nullptr;

		return n;
	}
};

template <typename T>
class Tree {
public:
	Node<T> *root = nullptr;

	virtual void insert(T );

	T getVal(Node<T> *);

	void levelOrder(std::list<T> &);

	void printInOrder(std::list<T> &);

	void printPostOrder(std::list<T> &);

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
