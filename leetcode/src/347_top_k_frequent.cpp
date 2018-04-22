#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

#include "347_top_k_frequent_test.h"
#include "debug.h"

using namespace std;

vector<int> top_k_sort(vector<int> &nums, int k) {
    unordered_map<int, int> counting_map;

    for (int i = 0; i < nums.size(); i++) {
        int el = nums[i];
        counting_map[el]++;
    }

    vector<pair<int, int>> counts;

    for (pair<int, int> kv : counting_map) {
        int el = kv.first;
        int cnt = kv.second;
        counts.push_back(pair<int, int>(cnt, el));
    }

    sort(counts.rbegin(), counts.rend());

    vector<int> result;
    for (int i = 0; i < k; i++) {
        int el = counts[i].second;
        result.push_back(el);
    }

    return result;
}

vector<int> top_k_buckets(vector<int> &nums, int k) {
    int size = nums.size();
    unordered_map<int, int> counting_map;

    for (int i = 0; i < nums.size(); i++) {
        int el = nums[i];
        counting_map[el]++;
    }

    vector<vector<int>> buckets(size + 1);
    for (pair<int, int> kv : counting_map) {
        int el = kv.first;
        int cnt = kv.second;
        buckets[cnt].push_back(el);
    }

    vector<int> result;
    for (int i = size; i >= 0; i--) {
        for (int el : buckets[i]) {
            result.push_back(el);
            if (result.size() >= k) {
                return result;
            }
        }
    }

    return result;
}

vector<int> TopKFrequentSolution::topKFrequent(vector<int> &nums, int k) {
    //return top_k_naive(nums, k);
    return top_k_buckets(nums, k);
}