#include <vector>
#include <unordered_map>
#include <iostream>
#include "815_bus_routes.h"

using namespace std;

unordered_map<int, vector<int>> inverted_index(vector<vector<int>> &routes) {
    int num_routes = routes.size();
    unordered_map<int, vector<int>> index;

    for (int r = 0; r < num_routes; r++) {
        vector<int> bus_routes = routes[r];
        for (int i = 0; i < bus_routes.size(); i++) {
            index[bus_routes[i]].push_back(r);
        }
    }

    return index;
}

int BusRoutesSolution::numBusesToDestination(vector<vector<int>> &routes, int S, int T) {
    unordered_map<int, vector<int>> index = inverted_index(routes);

    for (auto record : index) {
        int station = record.first;
        vector<int> buses = record.second;
        if (buses.size() <= 1) {
            continue;
        }

    }

    return 0;
}