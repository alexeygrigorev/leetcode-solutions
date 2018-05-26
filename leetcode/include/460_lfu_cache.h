
#include <unordered_map>
#include <set>

using namespace std;

struct LFUCacheNode {
    int key;
    int value;
    int freq;
    unsigned int last_update;
};

struct LFUCacheNode_compare {
    bool operator() (LFUCacheNode *left, LFUCacheNode *right) {
        if (left->freq == right->freq) {
            return left->last_update < right->last_update;
        }
        return left->freq < right->freq;
    }
};

class LFUCache {
public:
    LFUCache(int capacity);
    int get(int key);
    void put(int key, int value);

private:
    unordered_map<int, LFUCacheNode*> nodes;
    set<LFUCacheNode*, LFUCacheNode_compare> sorted_cache;

    int capacity;
    int current_capacity;
    unsigned int current_t;

    void evict_back();

    void update_counters(LFUCacheNode *node);
    LFUCacheNode* new_node(int key, int value);
};
