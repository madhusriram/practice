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
