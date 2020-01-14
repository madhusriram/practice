#include "linkedlist.hh"
#include <gtest/gtest.h>

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

	std::list<float> addedElements { 2.4, 3.5 };
	for (std::list<float>::const_iterator iterator = addedElements.begin(); 
					iterator != addedElements.end();
					++iterator) {
		dl.addToList(*iterator);
	}

	std::list<float> listElements; 
	dl.getListElements(listElements);

	ASSERT_EQ(listElements == addedElements, 1);
}

// Test even positioned elements are removed
TEST(DoublyCircularLinkedList, LinkTwoLists) {
	DoublyCircularLinkedList<int> l1;
	DoublyCircularLinkedList<int> l2;

	// list 1
	l1.addToList(1);
	l1.addToList(2);
	l1.addToList(3);

	// list 2 - append this to l2
	l2.addToList(4);
	l2.addToList(5);
	l2.addToList(6);

	// link 'em both!
	l1.linkTwoLists(l2);

	// length should be the addition of both, with l1 containing the joined list
	ASSERT_EQ(6, l1.length());

}

int main(int ac, char **av) {
	testing::InitGoogleTest(&ac, av);
	return RUN_ALL_TESTS();
}
