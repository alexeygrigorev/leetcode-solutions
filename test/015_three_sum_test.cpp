#include "015_three_sum.h"
#include "gtest/gtest.h"

using namespace std;


ThreeSumSolution *solution015 = new ThreeSumSolution;

void sort_vector_of_vectors(vector<vector<int>> &vec) {
    for (vector<int> v : vec) {
        sort(v.begin(), v.end());
    }
    sort(vec.begin(), vec.end());
}


TEST(ThreeSum, Test0) {
    vector<int> nums = {};

    vector<vector<int>> actual = solution015->threeSum(nums);
    vector<vector<int>> expected = {};

    EXPECT_EQ(actual, expected);
}

TEST(ThreeSum, Test1) {
    vector<int> nums = {-1,0,1,2,-1,-4};

    vector<vector<int>> actual = solution015->threeSum(nums);
    sort_vector_of_vectors(actual);

    vector<vector<int>> expected = {{-1,-1,2}, {-1,0,1}};
    sort_vector_of_vectors(expected);

    EXPECT_EQ(actual, expected);
}

TEST(ThreeSum, Test2) {
    vector<int> nums = {0, 0, 0, 1, -1, 2, -2, -2, 4};

    vector<vector<int>> actual = solution015->threeSum(nums);
    sort_vector_of_vectors(actual);

    vector<vector<int>> expected = {{-2,-2,4}, {-2,0,2}, {-1,0,1}, {0,0,0}};
    sort_vector_of_vectors(expected);

    EXPECT_EQ(actual, expected);
}

TEST(ThreeSum, Test3) {
    vector<int> nums = {-12, 0, 2, 6, 6, 10, 12, 15};

    vector<vector<int>> actual = solution015->threeSum(nums);
    sort_vector_of_vectors(actual);

    vector<vector<int>> expected = {{-12,0,12}, {-12,2,10}, {-12,6,6}};
    sort_vector_of_vectors(expected);

    EXPECT_EQ(actual, expected);
}