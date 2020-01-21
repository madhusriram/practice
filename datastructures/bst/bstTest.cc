#include "bst.hh"
#include <gtest/gtest.h>
#include <list>

// test sorted order
TEST(BSTUnbalanced, TreePrint) {
	BST<int> bst;

	bst.insert(10);
	bst.insert(8);
	bst.insert(12);
	
	std::list<int> out;
	bst.levelOrder(out);
	std::list<int> expectedlevel{10,8,12};
	ASSERT_EQ(out == expectedlevel, 1);
	out.clear();

	bst.printInOrder(out);
	std::list<int> expectedIn{8,10,12};
	ASSERT_EQ(out == expectedIn, 1);
	out.clear();

	bst.printPostOrder(out);
	std::list<int> expectedOut{8,12,10};
	ASSERT_EQ(out == expectedOut, 1);
	out.clear();

	bst.printInOrderWithStack(out);
	ASSERT_EQ(out == expectedIn, 1);
	out.clear();

}

// Start here!
int main(int ac, char **av) {
	testing::InitGoogleTest(&ac, av);

	return RUN_ALL_TESTS();
}
