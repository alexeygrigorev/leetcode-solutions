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
