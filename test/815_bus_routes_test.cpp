#include "815_bus_routes.h"
#include "gtest/gtest.h"

using namespace std;

BusRoutesSolution *solution815 = new BusRoutesSolution;

TEST(BusRoutes, Test0) {
    vector<vector<int>> routes = {{1, 2, 7}, {3, 6, 7}};
    int S = 1;
    int T = 6;
    int expected = 2;
    int actual = solution815->numBusesToDestination(routes, S, T);
    EXPECT_EQ(actual, expected);
}

TEST(BusRoutes, Test1) {
    vector<vector<int>> routes = {{1, 2, 7}};
    int S = 1;
    int T = 2;
    int expected = 1;
    int actual = solution815->numBusesToDestination(routes, S, T);
    EXPECT_EQ(actual, expected);
}

TEST(BusRoutes, Test2) {
    vector<vector<int>> routes = {
        {0, 1, 2}, // 0
        {0, 2, 3}, // 1
        {0, 3, 4}, // 2
        {2, 3, 5}, // 3
        {1, 2, 6}, // 4
        {2, 5, 6}, // 5
        {3, 5, 7}, // 6
        {3, 4, 7}, // 7
        {6, 8}, // 8
        {5, 8}, // 9
        {7, 8}, // 10
    };

    int S = 0;
    int T = 8;
    int expected = 3;
    int actual = solution815->numBusesToDestination(routes, S, T);
    EXPECT_EQ(actual, expected);
}
