// Class implementing singly, doubly and, singly and doubly circular linked lists

#ifndef _LINKEDLIST_H_
#define	_LINKEDLIST_H_

#include <iostream>

template <typename T>
class Node {
	protected:
		struct node {
			T data;
			struct node *next;
			struct node *prev;
		};

	public:
		typedef struct node listNode;

		// Create a node
		listNode* createNode(T v) {
			listNode *n = new(listNode);
			n->data = v;
			n->next = nullptr;
			n->prev = nullptr;
			return n;
		}
		
		// the list
		listNode *l = nullptr;

		// temporary to store all intermediate node creations
		listNode *tmp = nullptr;

		// destructor - destroy the list
		~Node() {
			while (l != nullptr) {
				tmp = l->next;
				delete(l);
				l = tmp;
			}			
		};
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
class DoublyCircularLinkedList : public Node<T> {
	public:
		// constructor
		DoublyCircularLinkedList() { };

		// add node
		void addNode(T v);

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
};

#include "doublycircular_impl.hh"
#endif // _LINKEDLIST_H_
