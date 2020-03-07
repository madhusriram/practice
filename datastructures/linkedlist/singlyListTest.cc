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

TEST(SinglyList, ReverseKGroup) {
	SinglyList<int> sl;

	std::list<int> l{1,2,3,4};
	sl.push_back(l);

	sl.reverseKGroup(2);

	std::list<int> listEl;
	sl.getListElements(listEl);
	std::list<int> expectedResult{2,1,4,3};
	ASSERT_EQ(expectedResult == listEl, 1);

	sl.reverseKGroup(3);
	listEl.clear();
	sl.getListElements(listEl);
	expectedResult.clear();
	expectedResult = {4,1,2,3};
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

// Max sum of K consecutive nodes in a singly linked list
TEST(SinglyList, MaxSumOfK) {
	SinglyList<int> l;

	std::list<int> linput{1,2,3,4,5,4,3,2,1};
	l.push_back(linput);

	int res = l.maxSumOfK(5);
	ASSERT_EQ(res == 19, 1);

	res = l.maxSumOfK(3);
	ASSERT_EQ(res == 13, 1);

	res = l.maxSumOfK(10);
	ASSERT_EQ(res == -1, 1);
}

// Swap adjacent nodes
TEST(SinglyList, SwapAdjacent) {
	// odd numbered list
	SinglyList<int> l;
	std::list<int> linput{1,2,3,4,5};
	l.push_back(linput);
	l.swapNodes();

	std::list<int> expected{2,1,4,3,5};
	std::list<int> listEl;
	l.getListElements(listEl);

	ASSERT_EQ(listEl == expected, 1);

	// even numbered list
	SinglyList<int> l2;
	std::list<int> l2input{1,2,3,4,5,6};
	l2.push_back(l2input);
	l2.swapNodes();

	std::list<int> expected2{2,1,4,3,6,5};
	std::list<int> listEl2;
	l2.getListElements(listEl2);

	ASSERT_EQ(listEl2 == expected2, 1);
}

// Is the list a palindrome?
TEST(SingyList, Is_Palindrome) {
	SinglyList<int> l;
	std::list<int> input{1,2,3,4,5};
	l.push_back(input);
	
	ASSERT_EQ(l.isPalindrome() == false, 1);

	SinglyList<int> l2;
	std::list<int> input2{1,2,3,2,1};
	l2.push_back(input2);

	ASSERT_EQ(true == l2.isPalindrome(), 1);

	SinglyList<int> l3;
	std::list<int> input3{1,2,3,4,4,3,2,1};
	l3.push_back(input3);

	ASSERT_EQ(true == l3.isPalindrome(), 1);

	SinglyList<int> l4;
	std::list<int> input4{1};
	l4.push_back(input4);

	ASSERT_EQ(true == l4.isPalindrome(), 1);
}

// Shuffle even number of nodes in a list
TEST(SinglyList, Shuffle) {
	SinglyList<int> l;
	std::list<int> input{1,2,3,4,5,6};
	l.push_back(input);
	
	// shuffle
	l.shuffleList();

	std::list<int> expected{4,1,5,2,6,3};
	std::list<int> listEl;
	l.getListElements(listEl);
	ASSERT_EQ(listEl == expected, 1);
}

// Merge sorted lists
/*TEST(SinglyList, DISABLED_Merge2SortedList) {
	SinglyList<int> l1;
	std::list<int> input1{1,2,4};
	l1.push_back(input1);

	SinglyList<int> l2;
	std::list<int> input2{1,3,4};
	l2.push_back(input2);

	// merge 2 lists
	SinglyList<int> *res = l.merge2(l1, l2);

	std::list<int> expected{1,1,2,3,4,4};
	std::list<int> listEl;
	res.getListElements(listEl);

	ASSERT_EQ(expected == listEl, 1);
}
*/

// Reverse M to N nodes only 
TEST(SinglyList, ReverseMtoN) {
	SinglyList<int> l;
	std::list<int> input{1,2,3,4,5};
	l.push_back(input);

	l.reverseMtoN(1,5);

	std::list<int> expected{5,4,3,2,1};
	std::list<int> listEl;
	l.getListElements(listEl);

	ASSERT_EQ(expected == listEl, 1);

	l.reverseMtoN(2,4);
	listEl.clear();
	l.getListElements(listEl);
	expected.clear();
	expected = {5,2,3,4,1};

	ASSERT_EQ(expected == listEl, 1);

}

// odd numbered nodes first and then even numbered nodes
TEST(SinglyList, OddEven) {
	SinglyList<int> l1;
	std::list<int> input{2,1,3,5,6,4,7};
	l1.push_back(input);

	l1.oddEven();

	std::list<int> expected{2,3,6,7,1,5,4};
	std::list<int> listEl;
	l1.getListElements(listEl);

	ASSERT_EQ(listEl == expected, 1);
}

// Get integer value out of a list which has 0's and 1's
TEST(SinglyList, GetInt) {
	SinglyList<int> l;
	std::list<int> input{1,0,0,1,0,0,1,1,1,0,0,0,0,0,0};
	l.push_back(input);

	int res = l.getInt();
	ASSERT_EQ(res == 18880, 1);
}

// Start here!
int main(int ac, char **av) {
	testing::InitGoogleTest(&ac, av);
	return RUN_ALL_TESTS();
}
