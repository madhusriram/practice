#include "linkedlist.hh"

int main() {
	DoublyCircularLinkedList<int> dl; 

	dl.addNode(3);
	dl.addNode(2);
	dl.addNode(1);

	dl.traverseCircularList();

	return 0;
}
