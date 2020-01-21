#include <queue>
#include <stack>
#include "bst.hh"

template <typename T>
T Tree<T>::getVal(Node<T> *n) {
	return n->data;
}

// level order traversal of the tree
// put elements in a queue
template <typename T>
void Tree<T>::levelOrder(std::list<T>& out) {
	std::queue<Node<T> *> q;

	Node<T> *tmp = root;
	
	// push root first
	q.push(tmp);

	while (! q.empty()) {
		Node<T> *n = q.front();

		out.push_back(n->data);
		if (n->left != nullptr)
			q.push(n->left);
		if (n->right != nullptr)
			q.push(n->right);

		q.pop();
	}
}

// in order printer helper
template <typename T>
void Tree<T>::recurseInOrder(std::list<T>& q, Node<T>* n) {
	if (n == nullptr)
		return;
	
	recurseInOrder(q, n->left);
	q.push_back(n->data);
	recurseInOrder(q, n->right);	
}

// post order helper
template <typename T>
void Tree<T>::recursePostOrder(std::list<T>& q, Node<T>* n) {
	if (n == nullptr)
		return;

	recursePostOrder(q, n->left);
	recursePostOrder(q, n->right);
	q.push_back(n->data);
}

// in order
template <typename T>
void Tree<T>::printInOrder(std::list<T>& out) {
	Node<T> *tmp = root;

	recurseInOrder(out, tmp);
}

// no recursion but uses stack
// depth-first - in-order
template <typename T>
void Tree<T>::printInOrderWithStack(std::list<T> &out) {
	Node<T> *tmp = root;
	std::stack<Node<T> *> s;

	while (tmp || !s.empty()) {
	
		// add to stack left subtree
		while (tmp) {
			s.push(tmp);
			tmp = tmp->left;
		}
		Node<T> *top = s.top();
		out.push_back(top->data);
		s.pop();

		// add right subtree now!
		tmp = top->right;
	}
}

// Recursive depth first requires a stack space equal to the length of the
// tree height which might be considerable if the tree is unbalanced.
template <typename T>
void Tree<T>::printInOrderWithoutRecursion(std::list<T> &out) {

}

// post order
template <typename T>
void Tree<T>::printPostOrder(std::list<T>& out) {
	Node<T> *tmp = root;
	
	recursePostOrder(out, tmp);
}

template <typename T>
void BST<T>::insert(T d) {
	if (this->root == nullptr) {
		this->root = Node<T>::createNode(d);	
		return;
	}

	insert(d, this->root);
}

// recursively insert the node at the right position
// does not balance the tree
template <typename T>
void BST<T>::insert(T d, Node<T> *node) {
	if (node == nullptr) {
		return;
	} else if (this->getVal(node) > d) {
		insert(d, node->left);
		insertLeft(d, node);
	} else if (this->getVal(node) < d) {
		insert(d, node->right);
		insertRight(d, node);
	}
}

template <typename T>
void BST<T>::insertLeft(T d, Node<T> *node) {
	node->left = Node<T>::createNode(d);
}

template <typename T>
void BST<T>::insertRight(T d, Node<T> *node) {
	node->right = Node<T>::createNode(d);
}

template <typename T>
unsigned int Tree<T>::getLength() {

}
