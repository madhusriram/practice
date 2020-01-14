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

		// add to list 1 value
		void addToList(T v);

		// add to list from a list
		void addToList(const std::list<T>);

		// traverse the list
		void traverseCircularList();

		// link 2 circular lists
		void linkTwoLists(DoublyCircularLinkedList<T> &);

		// split list
		void splitCircularLists(DoublyCircularLinkedList &);

		// delete odd positions
		void deleteOddPos();

		// delete even positions
		void deleteEvenPos();

		// delete the list;
		void deleteList();

		// dump's 'list' into the list passed in by the user
		void getListElements(std::list<T> &);

		// reverse the list
		void reverse();

		// delete at an index
		bool deleteAtPos(int pos);

		// length of the list
		unsigned int length();
	private:
		// is end of list
		bool isEndOfList(Node<T> *, Node<T> *);

		// deleteAtPos helper
		void deleteNode(Node<T> *tmp);
};

#include "doublycircular_impl.hh"

#endif // _LINKEDLIST_H_
