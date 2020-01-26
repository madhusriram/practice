#include "linkedlist.hh"
#include <gtest/gtest.h>

TEST(SinglyList, ListElements) {
	SinglyList<int> sl;

	ASSERT_EQ(0, sl.getLength());

	std::list<int> l{1,2,3};
	
	sl.push_front(l);

	sl.push_back(4);
	sl.push_back(5);

	std::list<int> expectedResult{3,2,1,4,5};

	std::list<int> listEl;
	sl.getListElements(listEl);
	ASSERT_EQ(listEl == expectedResult, 1);
}

TEST(SinglyList, DeleteOddPos) {
	SinglyList<int> sl;

	std::list<int> l{1,2,3,4};
	sl.push_back(l);

	sl.deleteOddPos();

	std::list<int> listEl;
	sl.getListElements(listEl);
	std::list<int> expectedResult{2,4};
	ASSERT_EQ(expectedResult == listEl, 1);
}

TEST(SinglyList, DeleteEvenPos) {
	SinglyList<int> sl;

	std::list<int> l{1,2,3,4};
	sl.push_back(l);

	sl.deleteEvenPos();

	std::list<int> listEl;
	sl.getListElements(listEl);
	std::list<int> expectedResult{1,3};
	ASSERT_EQ(expectedResult == listEl, 1);
}

TEST(SinglyList, Reverse) {
	SinglyList<int> sl;

	std::list<int> l{1,2,3,4};
	sl.push_back(l);

	sl.reverse();

	std::list<int> listEl;
	sl.getListElements(listEl);
	std::list<int> expectedResult{4,3,2,1};
	ASSERT_EQ(expectedResult == listEl, 1);
}

TEST(SinglyList, RemoveNthFromEnd) {
	SinglyList<int> sl;

	std::list<int> l {1};
	sl.push_back(l);

	sl.removeNthFromEnd(2);

	std::list<int> listEl;
	sl.getListElements(listEl);
	std::list<int> expectedResult{1};
	ASSERT_EQ(expectedResult == listEl, 1);
}

TEST(SinglyList, MiddleOfList) {
	SinglyList<int> sl;

	std::list<int> l{1,2,3};
	sl.push_back(l);

	int expectedResult = sl.middleOfList();

	ASSERT_EQ(expectedResult == 2, 1);
}

// Sum of lists
TEST(SinglyList, SumList) {
	SinglyList<int> l1;
	SinglyList<int> l2;
	SinglyList<int> sum;

	// l1 and l2 not empty
	std::list<int> l1list{1,2,3,4};
	l1.push_back(l1list);
	std::list<int> l2list{1,2,3,4};
	l2.push_back(l2list);

	l1.sumLists(l2, sum);

	std::list<int> listEl;
	sum.getListElements(listEl);
	std::list<int> expected {2,4,6,8};

	ASSERT_EQ(expected == listEl, 1);
	
	// l1 == null but not l2
	SinglyList<int> l3;
	SinglyList<int> l4;
	SinglyList<int> sum2;
	l3.push_back(l1list);

	l3.sumLists(l4, sum2);

	listEl.clear();
	sum2.getListElements(listEl);
	expected = {1,2,3,4};
	
	ASSERT_EQ(expected == listEl, 1);

	// no need to delete sum since it would be l2
	
	SinglyList<int> l5;
	SinglyList<int> l6;
	SinglyList<int> sum3;

	l6.push_back(l2list);

	l5.sumLists(l6, sum3);
	listEl.clear();
	sum3.getListElements(listEl);
	expected = {1,2,3,4};

	ASSERT_EQ(expected == listEl, 1);
}

// Sum of Last K consecutive nodes in a singly linked list
TEST(SinglyList, SumOfLastK) {
	SinglyList<int> l1;

	std::list<int> l1input{1,2,3,4,5};
	l1.push_back(l1input);

	int res = l1.sumOfLastK(5);
	ASSERT_EQ(res == 15, 1);

	res = l1.sumOfLastK(3);
	ASSERT_EQ(res == 12, 1);

	res = l1.sumOfLastK(6);
	ASSERT_EQ(res == -1, 1);
}

// Start here!
int main(int ac, char **av) {
	testing::InitGoogleTest(&ac, av);
	return RUN_ALL_TESTS();
}
