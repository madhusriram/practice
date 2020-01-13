// Class implementing singly, doubly and, singly and doubly circular linked lists

#ifndef _LINKEDLIST_H_
#define	_LINKEDLIST_H_

#include <iostream>
#include <list>

template <typename T>
struct Node {
	T data;
	Node<T> *next;
	Node<T> *prev;

	static Node<T> *createNode(T d) {
		Node<T> *n = new(Node<T>);
		n->data = d;
		n->next = nullptr;
		n->prev = nullptr;	

		return n;	
	}
};

/*
template <typename T>
class SinglyLinkedList : public Node<T> {
	public:
		// set data
		void addNode(T);

		// traverse the list
		void traverseList();

		void traverseCircular();

		void linkTwoLists();

		void sortList();

		void sortAndJoinTwoLists();
};

template <typename T>
class DoublyLinkedList : public Node<T> {
	public:
		// set data
		void addNode(T);

		// traverse the list
		void traverseList();

		void sortList();
};

*/
template <typename T>
class DoublyCircularLinkedList {
	public:
		// start of a list
		struct Node<T> *list = nullptr;
		
		// constructor
		DoublyCircularLinkedList() { };

		// add node
		void addToList(T v);

		// traverse the list
		void traverseCircularList();

		// link 2 circular lists
		void linkTwoLists();

		// split list
		void splitCircularLists(DoublyCircularLinkedList &);

		// delete odd positions
		void deleteOddPos();

		// delete even positions
		void deleteEvenPos();

		// delete the list;
		void deleteList();

		void getListElements(std::list<T> &);

		// is end of list
		bool isEndOfList(Node<T> *, Node<T> *);

		// length of the list
		unsigned int length();
};

#include "doublycircular_impl.hh"

#endif // _LINKEDLIST_H_
