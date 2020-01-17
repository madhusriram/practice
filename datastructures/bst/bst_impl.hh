#include <queue>

template <typename T>
T Tree<T>::getVal(Node<T> *n) {
	return n->data;
}

// level order traversal of the tree
// put elements in a queue
template <typename T>
void Tree<T>::levelOrder() {
	std::queue<Node<T> *> q;

	Node<T> *tmp = root;
	
	// push root first
	q.push(tmp);

	while (! q.empty()) {
		Node<T> *n = q.front();

		std::cout << n->data << " " ;
		
		if (n->left != nullptr)
			q.push(n->left);
		if (n->right != nullptr)
			q.push(n->right);

		q.pop();
	}
	std::cout << std::endl;
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
