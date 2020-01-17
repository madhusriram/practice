#include "linkedlist.hh"
#include <gtest/gtest.h>

TEST(Lru, Test) {
	LRU<int> lru(5);
	lru.addToCache(std::list<int>{1,2,3,4,5,6,7,8});

	std::list<int> cache;
	lru.getListElements(cache);

	std::list<int> expected {8,7,6,5,4};

	EXPECT_EQ(expected == cache, 1);
}

// Start here!
int main(int ac, char **av) {
	testing::InitGoogleTest(&ac, av);
	return RUN_ALL_TESTS();
}
