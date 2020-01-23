#include <queue>
#include <stack>
#include "bst.hh"

template <typename T>
T Tree<T>::getVal(Node<T> *n) {
	return n->data;
}

// build tree with an array input, without recursion, but, uses additional space
template <typename T>
void Tree<T>::buildTree(const T *arr) {
	int array_len = sizeof(arr)/arr[0];

	// {1,2,3,4,5,6,7} - tree
	// {0,1,2,3,4,5,6} - index
	// for k-levels, the total number of nodes will be 2^k - 1
	// How to find values in the array?
	// With array_len we can find out the number of levels, k.
	
	std::queue<Node<T> *> q;
	root = Node<T>::createNode(arr[0]);
	q.push(root);
	int left = 0;
	int right = 0;
	int start = 0;
	int end = array_len - 1;

	// while traversing the array we would only need to traverse half the list
	int mid = end / 2;

	while (start < mid) {
		left = (2 * start) + 1;
		Node<T> *n = q.front();
		q.pop();

		n->left = Node<T>::createNode(arr[left]);
		q.push(n->left);
	
		// add right	
		right = (2*start) + 2;
		n->right = Node<T>::createNode(arr[right]);
		q.push(n->right);
		
		start++;
	}
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

// connect to next node
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// Output: level order print with null next indicated as a '#'
// 			1->#
// 		 2   ->  3 -> #
//    4 -> 5 -> 6 -> 7 -> #   
// One-way to do this is to do breadth first search, put all elements in a queue,
// and re-iterate them. This is O(2N) operation
// Works only for a complete binary tree
template <typename T>
void Tree<T>::buildNextTree() {
	Node<T> *tmp = root;
	Node<T> *prev = nullptr;

	std::queue<Node<T> *> q;
	q.push(tmp);

	int i = 0;
	int nodesInLevel = 0;

	while (!q.empty()) {
		nodesInLevel = 1 << i;
		for (int j = 0; j < nodesInLevel; j++) {
 			Node<T> *n = q.front();
			q.pop();
			if (prev != nullptr)
				prev->next = n;
			
			if (n->left && n->right) {
				q.push(n->left);
				q.push(n->right);
			}

			prev = n;			
		}
		prev = nullptr;

		i++;
	}
}

// Do a new kind of Breadth first search printing nodes with connected next
// but traversing level order
// The tree in connectToNext() should be printed as 1 # 2 3 # 4 5 6 7 #
template <typename T>
void Tree<T>::printNextTree(std::string& res) {
	std::queue<Node<T> *> q;
	Node<T> *tmp = root;
	// push root first
	q.push(tmp);

	while (! q.empty()) {
		Node<T> *n = q.front();
		res.append(std::to_string(n->data));
		res.append(" ");
		if (n->next == nullptr) {
			res.append("# ");
		}
		if (n->left && n->right) {
			q.push(n->left);
			q.push(n->right);
		}

		q.pop();
	}
	// remove trailing " "
	res.pop_back();
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
