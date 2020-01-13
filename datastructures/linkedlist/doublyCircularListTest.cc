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
TEST(DoublyCircularLinkedList, DeleteEvenPost) {


}

int main(int ac, char **av) {
	testing::InitGoogleTest(&ac, av);
	return RUN_ALL_TESTS();
}
