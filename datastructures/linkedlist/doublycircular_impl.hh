using namespace std;

// this used coz the the derived templated class has no idea about the dependant
// names from the base class. This necissitates that the derived class be made
// aware of the base class objects using the this-> (or) use Node<T>::tmp
// Link: https://isocpp.org/wiki/faq/templates#nondependent-name-lookup-members
template <typename T>
void DoublyCircularLinkedList<T>::addNode(T v) {
	this->tmp = this->createNode(v);
	this->tmp->next = this->l;
	
	// if not the first node to the list
	if (this->l != nullptr) {
		this->tmp->prev = this->l->prev;
	}

	this->l = this->tmp;

}

template <typename T>
void DoublyCircularLinkedList<T>::traverseCircularList() {
	this->tmp = this->l;
	int i = 0;

	while ( this->tmp != nullptr ) {
		cout << "Index: " << i << "; ";
		cout << this->tmp->data << endl;
		this->tmp = this->tmp->next;
	}
}

// delete odd positions in the list
template <typename T>
void DoublyCircularLinkedList<T>::deleteOddPos() {
	

}
