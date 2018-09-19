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

int MaxHistRectangleSolution::largestRectangleArea(vector<int> &heights) {
    return largest_area_naive(heights);
}


