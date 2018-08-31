#include <cstdio>
#include "042_trapping_water.h"

int TrappingWaterSolution::max(vector<int> &array) {
    int m = array[0];

    for (int i = 1; i < array.size(); i++) {
        if (array[i] > m) {
            m = array[i];
        }
    }

    return m;
}

int TrappingWaterSolution::trap(vector<int> &height) {
    if (height.size() <= 1) {
        return 0;
    }

    int m = max(height);

    int left = 0;
    int right = height.size() - 1;
    int sum = 0;

    int left_max = height[left];
    while (left < right && height[left] < m) {
        if (height[left] <= left_max) {
            sum = sum + (left_max - height[left]);
        } else {
            left_max = height[left];
        }
        left++;
    }

    int right_max = height[right];
    while (left < right && height[right] < m) {
        if (height[right] <= right_max) {
            sum = sum + (right_max - height[right]);
        } else {
            right_max = height[right];
        }
        right--;
    }

    left++;
    while (left < right) {
        sum = sum + (m - height[left]);
        left++;
    }

    return sum;
}
