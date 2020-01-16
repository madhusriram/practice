
// adds to the beginning of the list
template <typename T>
void SinglyList<T>::push_front(T v) {
	Node<T> *tmp = Node<T>::createNode(v);

	length++;

	if (list == nullptr)
		last = tmp;

	tmp->next = list;
	list = tmp;
}


// adds to the beginning of the list from a list
template <typename T>
void SinglyList<T>::push_front(std::list<T> v) {
	for (typename std::list<T>::const_iterator it = v.begin(); it != v.end(); it++) {
		Node<T> *tmp = Node<T>::createNode(*it);

		length++;

		if (list == nullptr)
			last = tmp;
		tmp->next = list;
		list = tmp;
	}
}

// adds to the end of a list
template <typename T>
void SinglyList<T>::push_back(T v) {
	Node<T> *tmp = Node<T>::createNode(v);

	length++;

	if (list == nullptr) { 
		list = last = tmp;
		return;
	}

	last->next = tmp;
	last = tmp;
}


// adds to the end of the list a bunch of values
template <typename T>
void SinglyList<T>::push_back(std::list<T> v) {
	for (typename std::list<T>::const_iterator it = v.begin(); it != v.end(); it++) {
		length++;
		Node<T> *tmp = Node<T>::createNode(*it);
		if (list == nullptr) {
			list = last = tmp;
			continue;
		}
		last->next = tmp;
		last = tmp;
	}
}


// for debugging!
template <typename T>
void SinglyList<T>::traverseList() {
	Node<T> *tmp = list;

	while (tmp != nullptr) {
		std::cout << tmp->data << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl;	
}

template <typename T>
void SinglyList<T>::getListElements(std::list<T> &l) {
	Node<T> *tmp = list;

	while (tmp != nullptr) {
		l.push_back(tmp->data);
		tmp = tmp->next;
	}	
}

// 1 2 3 4 5
//
// do not use the last pointer
// should be harmless if there is no "n"th node from the end
template <typename T>
void SinglyList<T>::removeNthFromEnd(int n) {
	Node<T> *tmp = list;
	// advance this pointer only after having tmp moved further along the \
	// list after "n" pos
	Node<T> *deletePtr = list;
	Node<T> *prev = nullptr;

	int delta = 0;

	if (list == nullptr)
		return;
	else if (list->next == nullptr && n > 1)
		return;
 
	while (tmp->next != nullptr) {
		tmp = tmp->next;
		
		if (delta < n)
			delta++;
		
		// start moving the deletePtr
		if (delta == n) {
			prev = deletePtr;
			deletePtr = deletePtr->next;
		}
	}
	// if first node
	if (deletePtr == list) {
		Node<T> *next = list->next;
		delete(deletePtr);
		list = next;
	} else {
		// else, just tie nodes
		prev->next = deletePtr->next;
		delete(deletePtr);
	}
}

// Reverse a list
// Without recursion and with 3 pointers
// Save previous node to tie the next nodes new next
// O(n)
template <typename T>
void SinglyList<T>::reverse() {
	Node<T> *prev = nullptr;
	Node<T> *savenext = nullptr;

	while (list != nullptr) {
		savenext = list->next;
		list->next = prev;
		prev = list;
		list = savenext;
	}
	// set to head
	list = prev;
}

// slowPtr moves 1 step closer than the regular "tmp" pointer
// Can be solved through tortoise and hare logic!
// 1 2 3
template <typename T>
void SinglyList<T>::deleteOddPos() {
	Node<T> *fastPtr = list;
	Node<T> *slowPtr = list;
	bool start = true;

	if (list == nullptr)
		return;
	else if (list->next == nullptr) {
		delete list;
		return;
	}

	while (slowPtr != nullptr && fastPtr != nullptr) {
		slowPtr->next = fastPtr->next;
		delete(fastPtr);
		
		slowPtr = slowPtr->next;
		if (slowPtr != nullptr)
			fastPtr = slowPtr->next;

		// this is the only change with this and deleteEvenPos
		if (start) {
			list = slowPtr;
			start = false;
		}
	}
}

// Use fast and slow pointer logic
template <typename T>
void SinglyList<T>::deleteEvenPos() {
	Node<T> *fastPtr = list;
	Node<T> *slowPtr = list;

	if (list == nullptr || list->next == nullptr) {
		return;
	}

	fastPtr = list->next;

	while (slowPtr != nullptr && fastPtr != nullptr) {
		slowPtr->next = fastPtr->next;
		delete(fastPtr);
		slowPtr = slowPtr->next;
		if (slowPtr != nullptr)
			fastPtr = slowPtr->next;
	}
}
