#include "146_lru_cache.h"

using namespace std;

LRUCache::LRUCache(int capacity) {
    this->front = nullptr;
    this->back = nullptr;
    this->capacity = capacity;
    this->current_capacity = 0;
}

int LRUCache::get(int key) {
    if (this->capacity == 0) {
        return -1;
    }
    if (this->capacity == 1) {
        if (this->front == nullptr) {
            return -1;
        }
        if (this->front->key == key) {
            return this->front->value;
        }
        return -1;
    }

    LRUCacheNode *node = this->cache[key];

    if (node == nullptr) {
        return -1;
    }

    move_node_to_front(node);
    return node->value;
}

void LRUCache::put(int key, int value) {
    if (this->capacity == 0) {
        return;
    }
    if (this->capacity == 1) {
        delete this->front;

        this->front = new LRUCacheNode();
        this->front->key = key;
        this->front->value = value;
        return;
    }

    LRUCacheNode *node = this->cache[key];
    if (node != nullptr) {
        node->value = value;
        if (node == this->front) {
            return;
        }

        move_node_to_front(node);
        return;
    }

    if (this->current_capacity < this->capacity) {
        node = this->add_new_node_to_front(key, value);
        this->current_capacity++;

        if (this->back == nullptr) {
            this->back = node;
        }

        return;
    }

    evict_back();
    add_new_node_to_front(key, value);
}

void LRUCache::move_node_to_front(LRUCacheNode *node) {
    if (node == this->front) {
        return;
    }

    LRUCacheNode *prev = node->prev;
    LRUCacheNode *next = node->next;

    if (node == this->back) {
        this->back = prev;
    }

    if (prev != nullptr) {
        prev->next = next;
    }
    if (next != nullptr) {
        next->prev = prev;
    }

    node->prev = nullptr;
    this->front->prev = node;
    node->next = this->front;
    this->front = node;
}

LRUCacheNode* LRUCache::add_new_node_to_front(int key, int value) {
    LRUCacheNode *node = new LRUCacheNode();
    node->key = key;
    node->value = value;
    node->prev = nullptr;
    node->next = this->front;

    if (this->front != nullptr) {
        this->front->prev = node;
    }
    this->front = node;

    this->cache[key] = node;

    return node;
}

void LRUCache::evict_back() {
    if (this->back != nullptr) {
        int back_key = this->back->key;
        this->cache.erase(back_key);
    }

    delete this->back;

    this->back = this->back->prev;
    if (this->back != nullptr) {
        this->back->next = nullptr;
    }
}
