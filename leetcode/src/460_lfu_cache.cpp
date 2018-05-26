#include "460_lfu_cache.h"

LFUCache::LFUCache(int capacity) {
    this->capacity = capacity;
    this->current_capacity = 0;
    this->current_t = 0;
}

int LFUCache::get(int key) {
    if (this->capacity == 0) {
        return -1;
    }

    LFUCacheNode *node = this->nodes[key];
    if (node == nullptr) {
        return -1;
    }

    update_counters(node);
    return node->value;
}

void LFUCache::put(int key, int value) {
    if (this->capacity == 0) {
        return;
    }

    LFUCacheNode *node = this->nodes[key];
    if (node != nullptr) {
        node->value = value;
        update_counters(node);
        return;
    }

    if (current_capacity < capacity) {
        new_node(key, value);
        current_capacity++;
        return;
    }

    evict_back();
    new_node(key, value);
}

void LFUCache::evict_back() {
    LFUCacheNode *lfu = *(sorted_cache.begin());
    sorted_cache.erase(lfu);
    this->nodes.erase(lfu->key);
    delete lfu;
}

LFUCacheNode *LFUCache::new_node(int key, int value) {
    LFUCacheNode *node = new LFUCacheNode();
    node->key = key;
    node->value = value;
    node->freq = 1;
    node->last_update = this->current_t;
    this->current_t++;

    this->sorted_cache.insert(node);
    this->nodes[key] = node;

    return node;
}

void LFUCache::update_counters(LFUCacheNode *node) {
    sorted_cache.erase(node);

    node->freq++;
    node->last_update = this->current_t;
    this->current_t++;

    sorted_cache.insert(node);
}