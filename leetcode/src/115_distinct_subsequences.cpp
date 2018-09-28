#include "115_distinct_subsequences.h"

vector<vector_slice> DistinctSubsequencesSolution::build_index(string &s, string &t) {
    vector<vector_slice> result;

    for (int i = 0; i < t.size(); i++) {
        vector<int> data;
        char tc = t[i];

        for (int j = 0; j < s.size(); j++) {
            char sc = s[j];

            if (tc == sc) {
                data.push_back(j);
            }
        }

        vector_slice slice(data, 0);
        result.push_back(slice);
    }

    return result;
}

void DistinctSubsequencesSolution::count_subsequences(vector<vector_slice> &index, int pos, int *count) {
    vector_slice &head = index[pos];

    if (pos == index.size() - 1) {
        int size = head.data.size() - head.start;
        *count = *count + size;
        return;
    }

    for (int i = head.start; i < head.data.size(); i++) {
        int idx = head.data[i];

        for (int j = pos + 1; j < index.size(); j++) {
            vector_slice &slice = index[j];
            index[j].start = find_start(idx, slice);
        }

        count_subsequences(index, pos + 1, count);
    }
}

int DistinctSubsequencesSolution::find_start(int idx, vector_slice &slice) {
    vector<int> &data = slice.data;
    if (data.back() <= idx) {
        return data.size();
    }

    int l = 0, r = data.size() - 1;

    while (l <= r) {
        int m = (l + r) / 2;
        if (data[m] == idx) {
            return m + 1;
        }
        if (data[m] < idx) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    return l;
}

int DistinctSubsequencesSolution::num_distinct_naive_index(string s, string t) {
    vector<vector_slice> index = build_index(s, t);
    int count = 0;
    count_subsequences(index, 0, &count);
    return count;
}

int DistinctSubsequencesSolution::numDistinct(string s, string t) {
    return num_distinct_naive_index(s, t);
}
