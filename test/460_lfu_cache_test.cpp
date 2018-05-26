#include "460_lfu_cache.h"
#include "gtest/gtest.h"

using namespace std;

TEST(LFUCacheTest, Test0) {
    LFUCache *cache = new LFUCache(2);

    cache->put(1, 1);
    cache->put(2, 2);
    EXPECT_EQ(1, cache->get(1));
    cache->put(3, 3);    // evicts key 2
    EXPECT_EQ(-1, cache->get(2));
    EXPECT_EQ(3, cache->get(3));
    cache->put(4, 4);    // evicts key 1.
    EXPECT_EQ(-1, cache->get(1));
    EXPECT_EQ(3, cache->get(3));
    EXPECT_EQ(4, cache->get(4));
}

TEST(LFUCacheTest, Test1) {
    LFUCache *cache = new LFUCache(1);

    cache->put(1, 1);
    cache->put(2, 2);
    EXPECT_EQ(-1, cache->get(1));
    cache->put(3, 3);
    EXPECT_EQ(-1, cache->get(2));
    cache->put(4, 4);
    EXPECT_EQ(-1, cache->get(1));
    EXPECT_EQ(-1, cache->get(3));
    EXPECT_EQ(4, cache->get(4));
}

TEST(LFUCacheTest, Test3) {
    LFUCache *cache = new LFUCache(0);

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

TEST(LFUCacheTest, Test4) {
    LFUCache *cache = new LFUCache(2);

    cache->put(2, 2);
    cache->put(3, 3);
    EXPECT_EQ(3, cache->get(3));
    EXPECT_EQ(2, cache->get(2));
    cache->put(4, 4); // 3 is evicted because it's least recently used
    EXPECT_EQ(2, cache->get(2));
    EXPECT_EQ(-1, cache->get(3));
    EXPECT_EQ(4, cache->get(4));
}