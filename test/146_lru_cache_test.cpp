#include "146_lru_cache.h"
#include "gtest/gtest.h"

using namespace std;

TEST(LRUCacheTest, Test0) {
    LRUCache *cache = new LRUCache(2);

    cache->put(1, 1);
    cache->put(2, 2);
    EXPECT_EQ(1, cache->get(1));
    cache->put(3, 3);    // evicts key 2
    EXPECT_EQ(-1, cache->get(2));
    cache->put(4, 4);    // evicts key 1
    EXPECT_EQ(-1, cache->get(1));
    EXPECT_EQ(3, cache->get(3));
    EXPECT_EQ(4, cache->get(4));
}

TEST(LRUCacheTest, Test1) {
    LRUCache *cache = new LRUCache(1);

    cache->put(1, 1);
    cache->put(2, 2); // evicts 1
    EXPECT_EQ(-1, cache->get(1));
    cache->put(3, 3); // evicts key 2
    EXPECT_EQ(-1, cache->get(2));
    cache->put(4, 4); // evicts key 1
    EXPECT_EQ(-1, cache->get(1));
    EXPECT_EQ(-1, cache->get(3));
    EXPECT_EQ(4, cache->get(4));
}

TEST(LRUCacheTest, Test3) {
    LRUCache *cache = new LRUCache(0);

    cache->put(1, 1);
    cache->put(2, 2);
    EXPECT_EQ(-1, cache->get(1));
    cache->put(3, 3);
    EXPECT_EQ(-1, cache->get(2));
    cache->put(4, 4);
    EXPECT_EQ(-1, cache->get(1));
    EXPECT_EQ(-1, cache->get(3));
    EXPECT_EQ(-1, cache->get(4));
    // always -1
}

TEST(LRUCacheTest, Test4) {
    LRUCache *cache = new LRUCache(2);

    cache->put(2, 2);
    cache->put(3, 3);
    EXPECT_EQ(3, cache->get(3));
    EXPECT_EQ(2, cache->get(2));
    cache->put(4, 4);    // evicts key 3
    EXPECT_EQ(2, cache->get(2));
    EXPECT_EQ(-1, cache->get(3));
    EXPECT_EQ(4, cache->get(4));
}

TEST(LRUCacheTest, Test5) {
    LRUCache *cache = new LRUCache(2);

    cache->put(2, 1);
    cache->put(2, 2);
    EXPECT_EQ(2, cache->get(2));
    cache->put(1, 1);
    cache->put(4, 1);
    EXPECT_EQ(-1, cache->get(2));
}
