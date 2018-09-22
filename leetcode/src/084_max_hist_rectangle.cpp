#include <cstdlib>
#include <climits>
#include "084_max_hist_rectangle.h"

int MaxHistRectangleSolution::largest_area_naive(vector<int> &heights) {
    int max_area = 0;

    int n = heights.size();

    for (int i = 0; i < n; i++) {
        int h = heights[i];
        if (h == 0) {
            continue;
        }

        int area = h;

        int left = i - 1;
        while (left >= 0 && heights[left] >= h) {
            area = area + h;
            left--;
        }

        int right = i + 1;
        while (right < n && heights[right] >= h) {
            area = area + h;
            right++;
        }

        if (area > max_area) {
            max_area = area;
        }
    }

    return max_area;
}

int MaxHistRectangleSolution::largest_area_naive2(vector<int> &heights) {
    int max_area = 0;

    for (int i = 0; i < heights.size(); i++) {
        if (heights[i] == 0) {
            continue;
        }

        int min_height = INT_MAX;

        for (int j = i; j >= 0; j--) {
            int h = heights[j];
            if (h == 0) {
                break;
            }

            if (h < min_height) {
                min_height = h;
            }

            int len = i - j + 1;

            int area = min_height * len;
            if (area > max_area) {
                max_area = area;
            }
        }
    }

    return max_area;
}

MinIndexPair &MinSegmentTree::combine(MinIndexPair &left, MinIndexPair &right) {
    if (left.min_value < right.min_value) {
        return left;
    } else {
        return right;
    }
}

void MinSegmentTree::build(vector<int> &heights, int idx, int from, int to) {
    if (from == to) {
        values[idx].index = from;
        values[idx].min_value = heights[from];
        return;
    }

    int middle = (from + to) / 2;
    int left_idx = 2 * idx + 1;
    int right_idx = 2 * idx + 2;

    build(heights, left_idx, from, middle);
    build(heights, right_idx, middle + 1, to);

    values[idx] = combine(values[left_idx], values[right_idx]);
}

MinIndexPair &MinSegmentTree::min(int idx, int query_from, int query_to, int segment_from, int segment_to) {
    if (query_from == segment_from && query_to == segment_to) {
        return values[idx];
    }

    int middle = (segment_from + segment_to) / 2;
    int left_idx = 2 * idx + 1;
    int right_idx = 2 * idx + 2;

    if (query_from <= middle && query_to <= middle) {
        return min(left_idx, query_from, query_to, segment_from, middle);
    }

    if (query_from > middle && query_to > middle) {
        return min(right_idx, query_from, query_to, middle + 1, segment_to);
    }

    MinIndexPair &left = min(left_idx, query_from, middle, segment_from, middle);
    MinIndexPair &right = min(right_idx, middle + 1, query_to, middle + 1, segment_to);

    return combine(left, right);
};

MinSegmentTree::MinSegmentTree(vector<int> &heights) {
    this->size = heights.size();
    this->values = (MinIndexPair *) malloc(sizeof(MinIndexPair) * 4 * size);
    build(heights, 0, 0, size - 1);
}

int MinSegmentTree::find_min_index(int from, int to) {
    MinIndexPair &result = min(0, from, to, 0, size - 1);
    return result.index;
}

int MaxHistRectangleSolution::largest_area_recursive(vector<int> &heights, MinSegmentTree &st, int left, int right) {
    if (left > right) {
        return -1;
    }
    if (left == right) {
        return heights[left];
    }

    int min_idx = st.find_min_index(left, right);
    int h = heights[min_idx];
    int area = (right - left + 1) * h;

    int left_area = largest_area_recursive(heights, st, left, min_idx - 1);
    int right_area = largest_area_recursive(heights, st, min_idx + 1, right);

    return max(area, max(left_area, right_area));
}

int MaxHistRectangleSolution::largest_area_segment_tree(vector<int> &heights) {
    if (heights.empty()) {
        return 0;
    }

    MinSegmentTree st(heights);
    return largest_area_recursive(heights, st, 0, heights.size() - 1);
}

int MaxHistRectangleSolution::largest_area_stack(vector<int> &hist) {
    vector<int> stack;

    int i = 0;
    int n = hist.size();

    int max_area = 0;

    while (i < n) {
        if (stack.empty() || hist[i] >= hist[stack.back()]) {
            stack.push_back(i);
            i++;
            continue;
        }

        int min_idx = stack.back();
        stack.pop_back();

        int height = hist[min_idx];

        int width = i;
        if (!stack.empty()) {
            int prev_min_idx = stack.back();
            width = i - 1 - prev_min_idx;
        }

        int area = height * width;
        max_area = max(max_area, area);
    }

    while (!stack.empty()) {
        int min_idx = stack.back();
        stack.pop_back();

        int height = hist[min_idx];

        int width = i;
        if (!stack.empty()) {
            int prev_min_idx = stack.back();
            width = i - 1 - prev_min_idx;
        }

        int area = height * width;
        max_area = max(max_area, area);
    }

    return max_area;
}

int MaxHistRectangleSolution::largestRectangleArea(vector<int> &heights) {
    return largest_area_stack(heights);
}
