#include "LRUCache.hpp"

LRUCache::LRUCache(size_t capacity): capacity_{capacity}
{
}

LRUCache::~LRUCache()
{
}

bool LRUCache::Put(int key, int val){
    // cache miss
    if(cache_.find(key) == cache_.end()){
        lru_list_.push_front({key, val});
        cache_[key] = lru_list_.begin();
        return true;
    }

    // cache hit
    auto it = cache_[key];
    lru_list_.erase(it);
    lru_list_.push_front({key, val});
    cache_[key] = lru_list_.begin();
}

int LRUCache::Get(int key){
    return (cache_.find(key) == cache_.end()) ? -1 : (*cache_[key]).second;
}