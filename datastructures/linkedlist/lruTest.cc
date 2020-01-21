#include "linkedlist.hh"
#include <gtest/gtest.h>

TEST(Lru, TestWithCacheMiss) {
	LRU<int> lru(5);
	lru.addToCache(std::list<int>{1,2,3,4,5,6,7,8});

	std::list<int> cache;
	lru.getListElements(cache);

	std::list<int> expected {8,7,6,5,4};

	EXPECT_EQ(expected == cache, 1);
}

TEST(Lru, TestWithCacheHits) {
	LRU<int> lru(5);
	lru.addToCache(std::list<int>{1,2,3,4,5});
	bool res = lru.getCacheVal(4);
	EXPECT_EQ(res == true, 1);	// cache hit
	std::list<int> cache;
	std::list<int> expected{4,5,3,2,1};
	lru.traverseCircularList();

	lru.getListElements(cache);	// get state of the cache
	EXPECT_EQ(cache == expected, 1);

	expected.clear();
	cache.clear();
	expected = {6,4,5,3,2};
	lru.addToCache(6);
	lru.getListElements(cache);
	EXPECT_EQ(cache == expected, 1);
	lru.traverseCircularList();
}

// Start here!
int main(int ac, char **av) {
	testing::InitGoogleTest(&ac, av);
	return RUN_ALL_TESTS();
}
