#include "LRUCache.hpp"

LRUCache::LRUCache(size_t capacity): capacity_{capacity}
{
}

LRUCache::~LRUCache()
{
}

bool LRUCache::Put(int key, int val){
    // cache hit 
    if(cache_.find(key) != cache_.end()){
        auto& it = cache_[key];
        lru_list_.erase(it);
    }

    // cache miss
    lru_list_.push_front({key, val});
    cache_[key] = lru_list_.begin();

    if(cache_.size() > capacity_){
        int del_key = lru_list_.back().first;
        lru_list_.pop_back();
        cache_.erase(del_key);
    }
    return true;
}

int LRUCache::Get(int key){
    if(cache_.find(key) == cache_.end()){
        return -1;
    }

    int val{(*cache_[key]).second};
    lru_list_.erase(cache_[key]);
    lru_list_.push_front({key, val});
    cache_[key] = lru_list_.begin();
    return val;
}