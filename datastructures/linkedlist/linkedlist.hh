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

	// depending on the type of the list, the prev pointer might be of use
	// or no use!
	static Node<T> *createNode(T d) {
		Node<T> *n = new(Node<T>);
		n->data = d;
		n->next = nullptr;
		n->prev = nullptr;	

		return n;	
	}
};

template <typename T>
class SinglyList : public Node<T> {
	public:
		SinglyList() : length(0) { };

		// singly linked list
		struct Node<T> *list = nullptr;

		// add to list a value at the front
		void push_front(T v);

		// add to list from a list
		void push_front(const std::list<T>);

		// add to the list a value at the back
		void push_back(T v);

		// add to the list a bunch of values at the back
		void push_back(const std::list<T>);

		// traverse the list
		void traverseList();

		// link two lists
		void linkTwoLists(SinglyList<T> &);

		// split list
		void splitLists(SinglyList &);
		
		// delete odd positions
		void deleteOddPos();

		// delete even positions
		void deleteEvenPos();

		// reverse a list
		void reverse();

		// delete nth node from the end of the list
		void removeNthFromEnd(int n);

		// return data at the center of the list
		T middleOfList();

		// get length of a list
		unsigned int getLength() { return length; }

		void sortList();

		// sort and join two lists
		void sortAndJoinTwoLists();

		// copies linked list elements into the list passed in by the user
		void getListElements(std::list<T> &);
	
	private:
		void deleteNode(Node<T> *tmp);

		struct Node<T> *last = nullptr;

		unsigned int length;
};

/*
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
		
		// add to list 1 value
		void addToList(T v);

		// add to list from a list
		void addToList(const std::list<T>);

		// add to front of the list
		void addToFront(T v);

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

		// remove last node
		void removeTail();
	private:
		// is end of list
		bool isEndOfList(Node<T> *, Node<T> *);

		// deleteAtPos helper
		void deleteNode(Node<T> *tmp);
};

template <typename T>
class LRU : public DoublyCircularLinkedList<T> {
	public:
		LRU(unsigned int len = 0) : cacheLen(len) {};


		// adds to cache
		void addToCache(const std::list<T> &);


		void getCacheVal(std::list<T> &);
	
	private:
		unsigned int cacheLen;
};

#include "doublycircular_impl.hh"
#include "singlylist_impl.hh"
#include "lru_impl.hh"

#endif // _LINKEDLIST_H_
