#include "linkedlist.hh"
#include <gtest/gtest.h>

TEST(SinglyList, ListElements) {
	SinglyList<int> sl;

	ASSERT_EQ(0, sl.getLength());

	std::list<int> l{1,2,3};
	
	sl.push_front(l);

	sl.push_back(4);
	sl.push_back(5);

	std::list<int> addedList{3,2,1,4,5};

	std::list<int> listEl;
	sl.getListElements(listEl);
	ASSERT_EQ(listEl == addedList, 1);
}

TEST(SinglyList, DeleteOddPos) {
	SinglyList<int> sl;

	std::list<int> l{1,2,3,4};
	sl.push_back(l);

	sl.deleteOddPos();

	std::list<int> listEl;
	sl.getListElements(listEl);
	std::list<int> addedList{2,4};
	ASSERT_EQ(addedList == listEl, 1);
}

TEST(SinglyList, DeleteEvenPos) {
	SinglyList<int> sl;

	std::list<int> l{1,2,3,4};
	sl.push_back(l);

	sl.deleteEvenPos();

	std::list<int> listEl;
	sl.getListElements(listEl);
	std::list<int> addedList{1,3};
	ASSERT_EQ(addedList == listEl, 1);
}

TEST(SinglyList, Reverse) {
	SinglyList<int> sl;

	std::list<int> l{1,2,3,4};
	sl.push_back(l);

	sl.reverse();

	std::list<int> listEl;
	sl.getListElements(listEl);
	std::list<int> addedList{4,3,2,1};
	ASSERT_EQ(addedList == listEl, 1);
}

// Start here!
int main(int ac, char **av) {
	testing::InitGoogleTest(&ac, av);
	return RUN_ALL_TESTS();
}
