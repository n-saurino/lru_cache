#pragma once
#include <iostream>
#include <utility>
#include <list>
#include <unordered_map>

class LRUCache
{
public:
    LRUCache(size_t capacity);
    ~LRUCache();
    // put, get
    bool Put(int key, int val);
    int Get(int key);

private:
    /* data */
    size_t capacity_{}; 
    // this will handle the O(1) access to the vector for a specific key
    std::unordered_map<int, std::list<std::pair<int,int>>::iterator> cache_{};
    // need a linear ds to handle ordering
    std::list<std::pair<int, int>> lru_list_{};
};

