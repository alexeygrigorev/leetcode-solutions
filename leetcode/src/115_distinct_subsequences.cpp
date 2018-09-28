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

int DistinctSubsequencesSolution::count_recursive_naive(string s, string t) {
    if (t.empty()) {
        return 1;
    }

    if (s.size() < t.size()) {
        return 0;
    }

    int count = 0;

    for (int i = 0; i < s.size() - t.size() + 1; i++) {
        if (t[0] == s[i]) {
            count = count + count_recursive_naive(s.substr(i + 1), t.substr(1));
        }
    }

    return count;
}


int DistinctSubsequencesSolution::numDistinct(string s, string t) {
    return count_memo(s, t, 0, 0);
}

int DistinctSubsequencesSolution::count_memo(string &s, string &t, int pos_s, int pos_t) {
    printf("s = %d, t = %d\n", pos_s, pos_t);
    int t_size = t.size();
    int s_size = s.size();

    int t_remaining = t_size - pos_t;
    int s_remaining = s_size - pos_s;

    if (t_remaining <= 0) {
        return 1;
    }

    if (s_remaining < t_remaining) {
        return 0;
    }

    int count = 0;

    for (int i = pos_s; i < s.size() - t.size() + 1; i++) {
        if (t[pos_t] == s[i]) {
            count = count + count_memo(s, t, i + 1, pos_t + 1);
        }
    }

    return count;
}
