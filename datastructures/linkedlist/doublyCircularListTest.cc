#include "linkedlist.hh"
#include <gtest/gtest.h>

typedef std::list<int> intlist_t;
typedef std::list<float> floatlist_t;

// test list size
TEST(DoublyCircularLinkedList, ListSize) {
	DoublyCircularLinkedList<int> dl;

	ASSERT_EQ(0, dl.length());

	dl.addToList(3);
	dl.addToList(2);

	ASSERT_EQ(2, dl.length());
}

// test added elements order
TEST(DoublyCircularLinkedList, ListElements) {
	DoublyCircularLinkedList<float> dl;

	floatlist_t addedElements { 2.4, 3.5 };
	for (std::list<float>::const_iterator iterator = addedElements.begin(); 
					iterator != addedElements.end();
					++iterator) {
		dl.addToList(*iterator);
	}

	floatlist_t listElements; 
	dl.getListElements(listElements);

	ASSERT_EQ(listElements == addedElements, 1);
}

// Test linking two lists
TEST(DoublyCircularLinkedList, LinkTwoLists) {

	DoublyCircularLinkedList<int> l1;
	DoublyCircularLinkedList<int> l2;

	// list 1
	l1.addToList(intlist_t {1,2,3});

	// list 2 - append this to l2
	l2.addToList(intlist_t {4,5,6});

	// link 'em both!
	l1.linkTwoLists(l2);

	// length should be the addition of both, with l1 containing the joined list
	ASSERT_EQ(6, l1.length());

	intlist_t addedElements {1,2,3,4,5,6};
	intlist_t listElements;
	l1.getListElements(listElements);

	// l2's elements should be in l1 and at the end!
	ASSERT_EQ(listElements == addedElements, 1);
}

// Delete even positioned elements
TEST(DoublyCircularLinkedList, DeleteEvenPos) {


}

// Delete odd positioned elements
TEST(DoublyCircularLinkedList, DeleteOddPos) {

}

// Reverse the list
TEST(DoublyCircularLinkedList, Reverse) {

	DoublyCircularLinkedList<int> l1;

	l1.addToList(intlist_t {1,2,3,4});

	// reverse!
	l1.reverse();

	intlist_t addedElements {4,3,2,1};
	intlist_t listElements;
	l1.getListElements(listElements);

	ASSERT_EQ(listElements == addedElements, 1);

}

// Delete at a position
// return false if the position specified is larger then the list length
// List index starts from 1
TEST(DoublyCircularLinkedList, DeleteAtPos) {
	DoublyCircularLinkedList<int> l;

	l.addToList(intlist_t {1,2,3,4,5});

	bool res = l.deleteAtPos(10);
	ASSERT_EQ(res, false);

	res = l.deleteAtPos(2);
	ASSERT_EQ(res, true);

	intlist_t addedElements {1,3,4,5};
	intlist_t listElements;
	l.getListElements(listElements);

	ASSERT_EQ(listElements == addedElements, 1);
	ASSERT_EQ(l.length() == 4, 1);
}

// Start here!
int main(int ac, char **av) {
	testing::InitGoogleTest(&ac, av);
	return RUN_ALL_TESTS();
}
