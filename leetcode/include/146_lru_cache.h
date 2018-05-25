#include <unordered_map>

using namespace std;

struct LRUCacheNode {
    int key;
    int value;
    LRUCacheNode *prev;
    LRUCacheNode *next;
};

class LRUCache {
public:
    LRUCache(int capacity);
    int get(int key);
    void put(int key, int value);

private:
    unordered_map<int, LRUCacheNode*> cache;
    LRUCacheNode *front;
    LRUCacheNode *back;
    int capacity;
    int current_capacity;

    void move_node_to_front(LRUCacheNode *node);
    LRUCacheNode * add_new_node_to_front(int key, int value);
    void evict_back();

};