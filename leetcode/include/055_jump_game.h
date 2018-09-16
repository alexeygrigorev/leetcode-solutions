#include <vector>

using namespace std;

class JumpGameSolution {
public:
    bool can_reach_recursive(vector<int> &nums, int from, int to, vector<int> &memo);
    bool can_jump_recursive(vector<int> &nums);
    bool can_jump_linear(vector<int> &nums);
    bool canJump(vector<int> &nums);
};