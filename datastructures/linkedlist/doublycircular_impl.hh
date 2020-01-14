// adds to the end of the list
template <typename T>
void DoublyCircularLinkedList<T>::addToList(T v) {
	Node<T> *tmp = Node<T>::createNode(v);
		
	// if not the first node to the list
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

// Just to debug
template <typename T>
void DoublyCircularLinkedList<T>::traverseCircularList() {
	Node<T> *tmp = list;
	int i = 0;

	// run until you start looping over
	while ( tmp != nullptr ) {
		std::cout << "Index: " << i << "; ";
		std::cout << tmp->data << std::endl;
		tmp = tmp->next;
	
		i++;

		if ( isEndOfList(tmp, list) ) 
			break;
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
