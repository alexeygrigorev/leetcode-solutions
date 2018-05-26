
#include <unordered_map>

using namespace std;

struct LFUCacheNode {
    int key;
    int freq;
    unsigned int last_update;
    int value;
    LFUCacheNode *prev;
    LFUCacheNode *next;
};

class LFUCache {
public:
    LFUCache(int capacity);
    int get(int key);
    void put(int key, int value);

private:

    unordered_map<int, LFUCacheNode*> cache;
    LFUCacheNode *back;
    int capacity;
    int current_capacity;
    unsigned int current_t;

    void evict_back();

    void update_counters(LFUCacheNode *node);
    void bubble_up(LFUCacheNode *node);
    LFUCacheNode* new_node_to_back(int key, int value);
};
