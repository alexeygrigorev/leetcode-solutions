#include "015_three_sum.h"

#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

ThreeSumSolution::Triplet create_sorted_triplet(int a, int b, int c) {
    vector<int> vec = {a, b, c};
    sort(vec.begin(), vec.end());
    return ThreeSumSolution::Triplet(vec[0], vec[1], vec[2]);
}

vector<vector<int>> ThreeSumSolution::hash_count(vector<int> &nums) {

    if (nums.size() <= 2) {
        return {};
    }
    unordered_map<int, int> counter;

    for (int i = 0; i < nums.size(); i++) {
        counter[nums[i]]++;
    }

    vector<pair<const int, int>> counts;

    for (auto cnt : counter) {
        counts.push_back(cnt);
    }

    int n = counts.size();

    unordered_set<Triplet, TripletHasher> results;

    for (int i = 0; i < n; i++) {
        pair<const int, int> cnt_pair_a = counts[i];
        int a = cnt_pair_a.first;
        int count = cnt_pair_a.second;

        if (a == 0 && count >= 3) {
            results.insert(create_sorted_triplet(0, 0, 0));
        } else if (a != 0 && count >= 2) {
            int c = -2 * a;
            if (counter.find(c) != counter.end()) {
                results.insert(create_sorted_triplet(a, a, c));
            }
        }

        for (int j = i + 1; j < n; j++) {
            int b = counts[j].first;
            int c = -(a + b);

            if (c != a && c != b) {
                if (counter.find(c) != counter.end()) {
                    results.insert(create_sorted_triplet(a, b, c));
                }
            }
        }
    }

    vector<vector<int>> final_result;

    for (auto t : results) {
        final_result.push_back({t.a, t.b, t.c});
    }

    return final_result;
}

vector<vector<int>> ThreeSumSolution::threeSum(vector<int> &nums) {
    return hash_count(nums);
}
