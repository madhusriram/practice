// adds to the end of the list
template <typename T>
void DoublyCircularLinkedList<T>::addToList(T v) {
	Node<T> *tmp = Node<T>::createNode(v);
		
	// if the first node to the list
	if (list == nullptr) {
		tmp->prev = tmp;
		tmp->next = tmp;
		list = tmp;
		return;
	}

	// appends to the end of the list
	Node<T> *last = list->prev;
	last->next = tmp;	
	tmp->next = list;
	tmp->prev = last;
	last->next->next->prev = tmp;
}

// adds bunch of values to the end of the list from a list
template <typename T>
void DoublyCircularLinkedList<T>::addToList(std::list<T> l) {

	for (typename std::list<T>::iterator it = l.begin(); it != l.end(); ++it) {
		Node<T> *tmp = Node<T>::createNode(*it);

		// if the first node to the list
		if (list == nullptr) {
			tmp->prev = tmp;
			tmp->next = tmp;
			list = tmp;
			continue;
		}

		// append to end of the list
		Node<T> *last = list->prev;
		last->next = tmp;
		tmp->next = list;
		tmp->prev = last;
		last->next->next->prev = tmp;
	}
}

// add to front of list
template <typename T>
Node<T> *DoublyCircularLinkedList<T>::addToFront(const T v) {
	Node<T> *tmp = Node<T>::createNode(v);

	// if the first node
	if (list == nullptr) {
		tmp->prev = tmp;
		tmp->next = tmp;
		list = tmp;
		return list;
	}

	// append to front now!
	tmp->next = list;
	tmp->prev = list->prev;
	list->prev->next = tmp;
	list->prev = tmp;
	list = tmp;

	return tmp;
}

// move a node to the front of the list
template <typename T>
void DoublyCircularLinkedList<T>::moveToFront(Node<T> *n) {
	// already at the front
	if (n == list)
		return;

	Node<T> *oldHead = list;

	Node<T> *next = n->next;
	Node<T> *prev = n->prev;
	prev->next = next;
	next->prev = prev;	

	n->next = oldHead;
	n->prev = oldHead->prev;
	n->prev->next = n;

	// update the head
	list = n;
}


// remove the tail node
template <typename T>
void DoublyCircularLinkedList<T>::removeTail() {
	if (list == nullptr) {
		return;
	} else if (list->next == list) {
		delete list;
	}

	Node<T> *deleteNode = list->prev;
	Node<T> *prev = list->prev->prev;
	Node<T> *next = list;
	list->prev = prev;
	prev->next = list;

	delete(deleteNode);
}

// Just to debug
template <typename T>
void DoublyCircularLinkedList<T>::traverseCircularList() {
	Node<T> *tmp = list;

	// run until you start looping over
	while ( tmp != nullptr ) {
		std::cout << tmp->data << " "; 
		tmp = tmp->next;
	
		if ( isEndOfList(tmp, list) ) 
			break;
	}
	std::cout << std::endl;
}

// traverses through the list until the end is reached, cheap iterator pattern
// disadvantage: can only be used only once in the program
// advantage: Simple, and I do not know to implement an iterator pattern in C++
template <typename T>
struct Node<T> *DoublyCircularLinkedList<T>::traverse() {
	static Node<T> *tmp = list;

	if (tmp != nullptr) {
		auto ret = tmp;
		tmp = tmp->next;
		if (isEndOfList(tmp, list))
			return nullptr;
		return ret;
	}
}

// this could be done easier by tracking the length during adds but
// prefer this way to know how to traverse lists
template <typename T>
unsigned int DoublyCircularLinkedList<T>::length() {
	Node<T> *tmp = list;
	int count = 0;

	while ( tmp != nullptr ) {
		count++;
		tmp = tmp->next;

		if ( isEndOfList(tmp, list) )
			break;
	}
	return count;
}

// returns list elements in the same order as it is stored
template <typename T>
void DoublyCircularLinkedList<T>::getListElements(std::list<T>& l) {
	Node<T> *tmp = list;

	while (tmp != nullptr) {
		l.push_back(tmp->data);
		tmp = tmp->next;

		if (isEndOfList(tmp, list))
			break;
	}
}

template <typename T>
T DoublyCircularLinkedList<T>::getVal(Node<T> *n) {
	if (n)
		return n->data; 
}

template <typename T>
inline bool DoublyCircularLinkedList<T>::isEndOfList(Node<T> *a, Node<T> *b) {
	if (a == b) {
		return true;
	}

	return false;
}

// delete odd positions in the list
template <typename T>
void DoublyCircularLinkedList<T>::deleteOddPos() {
	
}

// delete even positions in the list
template <typename T>
void DoublyCircularLinkedList<T>::deleteEvenPos() {


}

// link 2 lists
template <typename T>
void DoublyCircularLinkedList<T>::linkTwoLists(DoublyCircularLinkedList<T>& l2) {

	Node<T> *l2list = l2.list;

	if (list == nullptr && l2list == nullptr)
		return;
	else if (list == nullptr) {
		list = l2list;
		return;
	}
	else if (l2list == nullptr) {
		return;
	}
		
	// save the start to tag the second list to the first!
	Node<T> *l1Start = list;
	// temp to traverse through the first list
	Node<T> *tmp = list;
	// save list 2's last element
	Node<T> *l2End = l2list->prev;

	// scroll through the end of the list 1
	while (tmp != nullptr) {
		tmp = tmp->next;

		if (isEndOfList(tmp, list)) {
			// move back one step
			tmp = tmp->prev;
			// add second list to tmp's next!
			tmp->next = l2list;
			l2list->prev = tmp;
			break;
		}
	}
	// tie list 1's head to list 2's tail and vice-versa
	l2End->next = l1Start;
	l1Start->prev = l2End;
}

// reverse list
// 1->2->3->4 becomes 4->3->2->1
template <typename T>
void DoublyCircularLinkedList<T>::reverse() {
	// for a single node there is no idea of reversing!
	if (list == nullptr || list == list->next)
		return;

	// save first and last
	Node<T> *oldstart = list;
	Node<T> *oldend = list->prev;
	
	Node<T> *savenext = list->next;
	Node<T> *l = list;

	// run through the list and reverse the pointers
	while (oldstart != savenext) {
		l->next = l->prev;
		l->prev = savenext;

		// advance to next
		l = savenext;
		savenext = savenext->next;
	}

	// last node needs to be updated!
	l->next = l->prev;
	l->prev = savenext;

	// update the list!
	list = oldend;
}

template <typename T>
void DoublyCircularLinkedList<T>::deleteNode(Node<T> *toBeRemovedNode) {
	toBeRemovedNode->prev->next = toBeRemovedNode->next;
	toBeRemovedNode->next->prev = toBeRemovedNode->prev;
	delete toBeRemovedNode;
}

// delete element at a index
template <typename T>
bool DoublyCircularLinkedList<T>::deleteAtPos(int pos) {
	unsigned int i = 1;
	unsigned int len = this->length();
	Node<T> *tmp = list;

	if (list == nullptr || pos > len) {
		return false;
	} else if (pos == 1 && len == 1) {
		delete list;
		return true;
	} else if (len == pos) { // last element
		deleteNode(list->prev);
		Node<T> *saved = list->prev;
		saved->prev->next = saved->next;
		saved->next->prev = saved->prev; // list->prev = saved->prev;
		delete saved;
		return true;
	}

	// go until you find the element to be removed
	while (i != pos) {
		tmp = tmp->next;
		i++;
	}

	deleteNode(tmp);
	return true;
}
