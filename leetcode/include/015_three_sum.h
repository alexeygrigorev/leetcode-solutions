#include <cstddef>
#include <vector>

using namespace std;

class ThreeSumSolution {
public:
    struct Triplet {
        int a, b, c;

        Triplet(int a, int b, int c): a(a), b(b), c(c) {};

        bool operator==(const Triplet &other) const {
            return a == other.a && b == other.b && c == other.c;
        }
    };

    struct TripletHasher {
        size_t operator() (const Triplet &t) const {
            return t.a + 31 * t.b + 101 * t.c;
        }
    };

    vector<vector<int>> hash_count(vector<int>& nums);
    vector<vector<int>> sort_count(vector<int>& nums);

    vector<vector<int>> threeSum(vector<int>& nums);
};