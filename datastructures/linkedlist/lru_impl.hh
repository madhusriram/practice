// The tail would be the least recently used, evict it and add values
// at the front
template <typename T>
void LRU<T>::addToCache(const std::list<T>& l) {
	int i = 0;

	// iterate through the input and add'em to the cache
	// add to the front
	for (typename std::list<T>::const_iterator it = l.begin(); it != l.end(); it++) {
		// remove at the tail and add at the front
		if (activeCacheLen >= cacheLen) {
			this->removeTail();
			cacheMap.erase(i);
			activeCacheLen--;
		}
		// good to add to the front
		Node<T> *n = this->addToFront(*it);
		cacheMap[i] = n;
		activeCacheLen++;
		i++;
	}
}

// same as above but just adds one key,val
template <typename T>
void LRU<T>::addToCache(const T k, const T v) {
	// remove only if the cache is full
	if (activeCacheLen >= cacheLen) {
		this->removeTail();
		cacheMap.erase(activeCacheLen);
	}

	// if key already present move to head
	// else add at the front
	if (cacheMap.find(k) == cacheMap.end()) {
		Node<T> *n = this->addToFront(v);
		cacheMap[k] = n;
	} else {
		this->moveToFront(cacheMap[k]);
	}
}

// return true of val is in the cache and, update the cache elements
// false if element is not found
// scroll through the list, if val found update the list so that val is at
// the start of the list. This method operates in O(n) time
// (OR)
// Use a map to index in to the list to find the value else return -1
template <typename T>
bool LRU<T>::getCacheVal(T k, T &out) {
	// did not find!
	if (cacheMap.find(k) == cacheMap.end()) {
		return false;
	}
		
	// if found, move that node to the front
	this->moveToFront(cacheMap[k]);
	out = this->getVal(cacheMap[k]);

	return true;
}
