#include "bst.hh"
#include <gtest/gtest.h>

// test sorted order
// TEST(BSTUnordered, SortedOrder) {
	BST<int> tree;

	ASSERT_EQ(0, tree.length());

	tree.addToTree(10);
	tree.addToTree(8);
	tree.addToTree(12);

	ASSERT_EQ(3, tree.length());
}

// Start here!
int main(int ac, char **av) {
	testing::InitGoogleTest(&ac, av);

	return RUN_ALL_TESTS();
}
