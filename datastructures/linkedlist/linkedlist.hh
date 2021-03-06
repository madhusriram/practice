// Class implementing singly, doubly and, singly and doubly circular linked lists

#ifndef _LINKEDLIST_H_
#define	_LINKEDLIST_H_

#include <iostream>
#include <list>
#include <map>

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

		// TODO link two lists
		void linkTwoLists(SinglyList<T> &);

		// TODO split list
		void splitLists(SinglyList &);
		
		// delete odd positions
		void deleteOddPos();

		// delete even positions
		void deleteEvenPos();

		// reverse a list
		void reverse();

		// reverse K nodes
		// https://leetcode.com/problems/reverse-nodes-in-k-group/
		void reverseKGroup(int k);

		// Reverse from position m to n
		// https://leetcode.com/problems/reverse-linked-list-ii/
		void reverseMtoN(int m, int n);

		// delete nth node from the end of the list
		void removeNthFromEnd(int n);

		// swap every 2 adjacent nodes 
		void swapNodes();

		// return data at the center of the list
		T middleOfList();

		// get length of a list
		unsigned int getLength() { return length; }

		// TODO
		void sortList();

		// sum 2 lists
		void sumLists(SinglyList<T>&, SinglyList<T>& );

		bool isPalindrome();

		// sort and join two lists
		void sortAndJoinTwoLists();

		// copies linked list elements into the list passed in by the user
		void getListElements(std::list<T> &);

		// sum of last K consecutive nodes in the list
		// https://www.geeksforgeeks.org/maximum-sum-of-k-consecutive-nodes-in-the-given-linked-list/
		int sumOfLastK(int );

		// Max sum of K consecutive nodes in the list
		// https://www.geeksforgeeks.org/maximum-sum-of-k-consecutive-nodes-in-the-given-linked-list/
		int maxSumOfK(int );

		// Stanford linked list prep
		// Assumes even number of elements in the list
		// For Input as 1 2 3 4 5 6
		// The output shall be 4 1 5 2 6 3
		void shuffleList();
	
		// odd even list
		// https://leetcode.com/problems/odd-even-linked-list/
		void oddEven();

		// Returned object would contain a list made by splicing together
		// the input lists
		// TODO
		// SinglyList<T> *mergeTwoLists(SinglyList<T> &, SinglyList<T> &);

		// Convert to integer from linked list
		// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
		int getInt();

		// Remove all occurences of a node in the list
		// https://leetcode.com/problems/remove-linked-list-elements/
		void removeNode(T );

	private:
		void deleteNode(Node<T> *tmp);

		// helper for reverseKGroup()
		Node<T> *reverseKNodes(Node<T> *, Node<T> *, Node<T> *);

		// reverse from the start till the end and return the new head
		Node<T> *reverse(Node<T> *);

		struct Node<T> *last = nullptr;

		unsigned int length;
};

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
		// return the node added so that lru cache gets to access in O(1)
		Node<T> *addToFront(const T v);

		// given pointer to a node on the list move it to the front
		void moveToFront(Node<T> *);

		// traverse the list
		void traverseCircularList();

		// traverses and returns current node
		struct Node<T> *traverse();

		// link 2 circular lists
		void linkTwoLists(DoublyCircularLinkedList<T> &);

		// split list
		void splitCircularLists(DoublyCircularLinkedList &);

		// get value of a node
		T getVal(Node<T> *);

		// delete odd positions
		// TODO
		void deleteOddPos();

		// delete even positions
		// TODO
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

// Operations supported are addToCache() and getCacheVal()
template <typename T>
class LRU : public DoublyCircularLinkedList<T> {
	public:
		LRU(unsigned int len = 0) : cacheLen(len), activeCacheLen(0) {};

		// map indexing the linked list
		std::map<T, Node<T> *> cacheMap;

		// adds to cache multiple values
		// keys would be the index of the list
		void addToCache(const std::list<T> &);

		// adds to cache single key
		void addToCache(const T , const T v);

		// gets cache value from the key
		// if key already present, moves the value to the head of the cache
		// if key not present returns false
		bool getCacheVal(T , T& out);

	private:
		unsigned int cacheLen;

		unsigned int activeCacheLen;
};

#include "doublycircular_impl.hh"
#include "singlylist_impl.hh"
#include "lru_impl.hh"

#endif // _LINKEDLIST_H_
