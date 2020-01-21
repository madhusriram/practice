// The tail would be the least recently used, evict it and add values
// at the front
template <typename T>
void LRU<T>::addToCache(const std::list<T>& l) {
	int i = 0;

	// iterate through the input and add'em to the cache
	// add to the front
	for (typename std::list<T>::const_iterator it = l.begin(); it != l.end(); it++) {
		// remove at the tail and add at the front
		if (i >= cacheLen) {
			this->removeTail();
			i--;
		}
		// good to add to the front
		this->addToFront(*it);
		i++;
	}
}

// same as above but just adds one
template <typename T>
void LRU<T>::addToCache(const T val) {
	this->removeTail();
	this->addToFront(val);
}

// return true of val is in the cache and, update the cache elements
// false if element is not found
// scroll through the list, if val found update the list so that val is at
// the start of the list. This method operates in O(n) time
template <typename T>
bool LRU<T>::getCacheVal(T val) {
	// traverseble copy of the list;
	Node<T> *tmp = this->list;

	while (true) {
		Node<T> *n = this->traverse();
		if (n == nullptr)
			return false;
		// if found in the list
		// move it to the head
		std::cout << n->data << " " << val << std::endl;
		if (n->data == val) {
			Node<T> *savenext = n->next;
			Node<T> *saveprev = n->prev;
			savenext->prev = saveprev;
			saveprev->next = savenext;

			// add to the front
			n->prev = this->list->prev;
			this->list->prev->next = n;
			n->next = this->list->next;
			this->list = n;	
			return true;
		}

	}


}
