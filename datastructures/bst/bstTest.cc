#include "bst.hh"
#include <gtest/gtest.h>

// test sorted order
TEST(BSTUnbalanced, SortedOrder) {
	BST<int> bst;

	//ASSERT_EQ(0, tree.length());

	bst.insert(10);
	bst.insert(8);
	bst.insert(12);
	bst.levelOrder();

	//ASSERT_EQ(3, tree.length());
}

// Start here!
int main(int ac, char **av) {
	testing::InitGoogleTest(&ac, av);

	return RUN_ALL_TESTS();
}
