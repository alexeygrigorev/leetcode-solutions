#include "097_interleaving_string.h"

bool InterleavingStringSolution::is_interleaving_recursive(string left, string right, string full) {
    if (left.empty() && right.empty() && full.empty()) {
        return true;
    }

    if (left.empty()) {
        return right == full;
    }
    if (right.empty()) {
        return left == full;
    }

    char lc = left[0];
    char rc = right[0];
    char fc = full[0];

    if (lc == fc) {
        if (is_interleaving_recursive(left.substr(1), right, full.substr(1))) {
            return true;
        }
    }

    if (rc == fc) {
        if (is_interleaving_recursive(left, right.substr(1), full.substr(1))) {
            return true;
        }
    }

    return false;
}

bool
InterleavingStringSolution::is_interleaving_memo(string left, string right, string full,
                                                 int left_idx, int right_idx, int full_idx,
                                                 unordered_map<triple, bool, triple_hash> &memo) {
    if (left_idx >= left.size() && right_idx >= right.size() && full_idx >= full.size()) {
        return true;
    }

    triple t(left_idx, right_idx, full_idx);
    if (memo.find(t) != memo.end()) {
        return memo[t];
    }

    if (left_idx >= left.size()) {
        return right.substr(right_idx) == full.substr(full_idx);
    }
    if (right_idx >= right.size()) {
        return left.substr(left_idx) == full.substr(full_idx);
    }

    char lc = left[left_idx];
    char rc = right[right_idx];
    char fc = full[full_idx];

    if (lc == fc) {
        if (is_interleaving_memo(left, right, full,
                                 left_idx + 1, right_idx, full_idx + 1, memo)) {
            memo[t] = true;
            return true;
        }
    }

    if (rc == fc) {
        if (is_interleaving_memo(left, right, full,
                                 left_idx, right_idx + 1, full_idx + 1, memo)) {
            memo[t] = true;
            return true;
        }
    }

    memo[t] = false;
    return false;
}

bool InterleavingStringSolution::isInterleave(string s1, string s2, string s3) {
    unordered_map<triple, bool, triple_hash> memo;
    return is_interleaving_memo(s1, s2, s3, 0, 0, 0, memo);
}

bool
InterleavingStringSolution::is_interleaving_memo2(string left, string right, string full, int left_idx, int right_idx,
                                                  int full_idx, unordered_set<long> &visited) {
    if (left_idx >= left.size() && right_idx >= right.size() && full_idx >= full.size()) {
        return true;
    }

    long t = left_idx;
    t = t << 32;
    t = t + right_idx;

    if (visited.find(t) != visited.end()) {
        return false;
    }

    if (left_idx >= left.size()) {
        return right.substr(right_idx) == full.substr(full_idx);
    }
    if (right_idx >= right.size()) {
        return left.substr(left_idx) == full.substr(full_idx);
    }

    char lc = left[left_idx];
    char rc = right[right_idx];
    char fc = full[full_idx];

    if (lc == fc) {
        if (is_interleaving_memo2(left, right, full,
                                  left_idx + 1, right_idx, full_idx + 1, visited)) {
            return true;
        }
    }

    if (rc == fc) {
        if (is_interleaving_memo2(left, right, full,
                                  left_idx, right_idx + 1, full_idx + 1, visited)) {
            return true;
        }
    }

    visited.insert(t);
    return false;
}

bool InterleavingStringSolution::is_interleaving_dp(string left, string right, string full) {
    int l1 = left.length();
    int l2 = right.length();

    if (l1 + l2 != full.length()) {
        return false;
    }

    vector<vector<bool>> table(l1 + 1, vector<bool>(l2 + 1, false));
    table[0][0] = true;

    for (int i1 = 1; i1 <= l1; i1++) {
        table[i1][0] = table[i1 - 1][0] && (left[i1 - 1] == full[i1 - 1]);
    }

    for (int i2 = 1; i2 <= l2; i2++) {
        table[0][i2] = table[0][i2 - 1] && (right[i2 - 1] == full[i2 - 1]);
    }

    for (int i1 = 1; i1 <= l1; i1++) {
        for (int i2 = 1; i2 <= l2; i2++) {
            bool from1 = table[i1 - 1][i2] && (left[i1 - 1] == full[i1 + i2 - 1]);
            bool from2 = table[i1][i2 - 1] && (right[i2 - 1] == full[i1 + i2 - 1]);
            table[i1][i2] = from1 || from2;
        }
    }

    return table[l1][l2];
}
