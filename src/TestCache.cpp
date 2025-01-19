#include "gtest/gtest.h"
#include "LRUCache.hpp"

// Test the basic functionality of the LRUCache constructor
TEST(LRUCacheTest, ConstructorTest) {
    LRUCache cache(2);
    EXPECT_EQ(cache.Get(1), -1);  // Cache is empty, should return -1
}

// Test the Put and Get functionality
TEST(LRUCacheTest, PutAndGetTest) {
    LRUCache cache(2);

    cache.Put(1, 1);
    cache.Put(2, 2);
    EXPECT_EQ(cache.Get(1), 1);  // Return 1
    EXPECT_EQ(cache.Get(2), 2);  // Return 2

    // Update existing key
    cache.Put(1, 10);
    EXPECT_EQ(cache.Get(1), 10); // Return updated value 10
}

// Test LRU eviction
TEST(LRUCacheTest, EvictionTest) {
    LRUCache cache(2);

    cache.Put(1, 1);
    cache.Put(2, 2);
    cache.Put(3, 3);  // Evicts key 1
    EXPECT_EQ(cache.Get(1), -1); // Key 1 was evicted
    EXPECT_EQ(cache.Get(2), 2);  // Key 2 is still present
    EXPECT_EQ(cache.Get(3), 3);  // Key 3 was just added

    cache.Put(4, 4);  // Evicts key 2
    EXPECT_EQ(cache.Get(2), -1); // Key 2 was evicted
    EXPECT_EQ(cache.Get(3), 3);  // Key 3 is still present
    EXPECT_EQ(cache.Get(4), 4);  // Key 4 was just added
}

// Test capacity constraints
TEST(LRUCacheTest, CapacityTest) {
    LRUCache cache(1);  // Cache with capacity 1

    cache.Put(1, 1);
    EXPECT_EQ(cache.Get(1), 1);  // Key 1 is present

    cache.Put(2, 2);             // Evicts key 1
    EXPECT_EQ(cache.Get(1), -1); // Key 1 was evicted
    EXPECT_EQ(cache.Get(2), 2);  // Key 2 is present
}

// Test edge cases
TEST(LRUCacheTest, EdgeCaseTest) {
    LRUCache cache(0);           // Cache with zero capacity
    cache.Put(1, 1);
    EXPECT_EQ(cache.Get(1), -1); // Cache cannot hold any keys
}