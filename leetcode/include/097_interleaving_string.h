#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct triple {
    int left;
    int right;
    int full;

    triple(int left, int right, int full): left(left), right(right), full(full) {}

    bool operator==(const triple &other) const {
        return left == other.left && right == other.right && full == other.full;
    }
};

struct triple_hash {
    size_t operator() (const triple &t) const {
        size_t result = t.left;
        result = 31 * result + t.right;
        result = 31 * result + t.full;
        return result;
    }
};


class InterleavingStringSolution {
public:
    bool is_interleaving_recursive(string left, string right, string full);

    bool is_interleaving_memo(string left, string right, string full,
                              int left_idx, int right_idx, int full_idx,
                              unordered_map<triple, bool, triple_hash> &memo);

    bool is_interleaving_memo2(string left, string right, string full,
                              int left_idx, int right_idx, int full_idx,
                              unordered_set<long> &visited);

    bool is_interleaving_dp(string left, string right, string full);

    bool isInterleave(string s1, string s2, string s3);
};
