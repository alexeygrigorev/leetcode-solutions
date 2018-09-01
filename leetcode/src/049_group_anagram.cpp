#include "049_group_anagram.h"

#include <unordered_map>
#include <algorithm>

vector<vector<string>> GroupAnagramSolution::groupAnagrams(vector<string> &strings) {
    unordered_map<string, vector<string>> groups;
    for (string s : strings) {
        string copy = s;
        sort(copy.begin(), copy.end());
        groups[copy].push_back(s);
    }

    vector<vector<string>> result;
    for (auto group : groups) {
        result.push_back(group.second);
    }

    return result;
}
