#include "460_lfu_cache.h"

LFUCache::LFUCache(int capacity) {
    this->capacity = capacity;
    this->current_capacity = 0;
    this->current_t = 0;
    this->back = nullptr;
}

int LFUCache::get(int key) {
    if (this->capacity == 0) {
        return -1;
    }
    if (this->capacity == 1) {
        if (this->back == nullptr) {
            return -1;
        }
        if (this->back->key == key) {
            return this->back->value;
        }
        return -1;
    }

    LFUCacheNode *node = this->cache[key];

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
    if (this->capacity == 1) {
        delete this->back;

        this->back = new LFUCacheNode();
        this->back->key = key;
        this->back->value = value;
        return;
    }

    LFUCacheNode *node = this->cache[key];
    if (node != nullptr) {
        node->value = value;
        update_counters(node);
        return;
    }

    if (current_capacity < capacity) {
        new_node_to_back(key, value);
        current_capacity++;
        return;
    }

    evict_back();
    new_node_to_back(key, value);
}

void LFUCache::evict_back() {
    if (this->back == nullptr) {
        throw exception();
    }

    LFUCacheNode *old_back = this->back;
    this->cache.erase(old_back->key);

    LFUCacheNode *prev = old_back->prev;

    if (prev != nullptr) {
        prev->next = nullptr;
        this->back = prev;
    } else {
        this->back = nullptr;
    }

    delete old_back;
}

LFUCacheNode *LFUCache::new_node_to_back(int key, int value) {
    LFUCacheNode *node = new LFUCacheNode();
    node->key = key;
    node->value = value;
    node->freq = 0;
    node->next = nullptr;
    node->prev = nullptr;

    this->cache[key] = node;

    if (this->back == nullptr) {
        this->back = node;
    } else {
        this->back->next = node;
        node->prev = this->back;
        this->back = node;
    }

    update_counters(node);
    return node;
}

void LFUCache::update_counters(LFUCacheNode *node) {
    node->freq++;
    node->last_update = this->current_t;
    this->current_t++;
    bubble_up(node);
}

void LFUCache::bubble_up(LFUCacheNode *node) {
    while (true) {
        LFUCacheNode *prev = node->prev;

        if (prev == nullptr) {
            return;
        }

        if (prev == node) {
            throw exception();
        }

        if (prev->freq > node->freq) {
            return;
        }

        if (prev->freq == node->freq) {
            if (prev->last_update > node->last_update) {
                return;
            }
        }

        LFUCacheNode *next = node->next;
        prev->next = next;
        if (next != nullptr) {
            next->prev = prev;
        }

        LFUCacheNode *prev_prev = prev->prev;
        node->prev = prev_prev;
        if (prev_prev != nullptr) {
            prev_prev->next = node;
        }

        node->next = prev;
        if (prev->prev == node) {
            throw exception();
        }
        prev->prev = node;

        if (node == this->back) {
            this->back = prev;
        }
    }
}