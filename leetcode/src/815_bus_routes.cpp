#include <vector>
#include <unordered_map>

#include "815_bus_routes.h"

using namespace std;

unordered_map<int, vector<int>> inverted_index(vector<vector<int>> &routes) {
    int num_routes = routes.size();
    unordered_map<int, vector<int>> index;

    for (int route = 0; route < num_routes; route++) {
        for (int station : routes[route]) {
            index[station].push_back(route);
        }
    }

    return index;
}

vector<vector<int>> build_graph(unordered_map<int, vector<int>> &index,
        int num_routes, int S, int T) {
    int start_node = num_routes;
    int end_node = num_routes + 1;
    int num_nodes = num_routes + 2;

    vector<vector<int>> graph(num_nodes);

    for (auto bus_stop : index) {
        int station = bus_stop.first;
        vector<int> routes = bus_stop.second;

        int num_buses = routes.size();
        if (num_buses <= 1) {
            continue;
        }

        for (int i : routes) {
            for (int j : routes) {
                if (i != j) {
                    graph[i].push_back(j);
                }
            }
        }
    }

    graph[start_node] = index[S];

    for (int n : index[T]) {
        graph[n].push_back(end_node);
    }

    return graph;
}

int shortest_path(vector<vector<int>> &graph, int start, int end) {
    int num_nodes = graph.size();

    vector<bool> visited(num_nodes, false);
    vector<int> queue(num_nodes, -1);
    vector<int> parent(num_nodes);

    int q_front = 0;
    int q_back = 0;

    visited[start] = true;
    queue[q_back] = start;
    q_back++;

    parent[start] = -1;

    while (q_back > q_front) {
        int node = queue[q_front];
        q_front++;

        for (int out : graph[node]) {
            if (!visited[out]) {
                visited[out] = true;

                queue[q_back] = out;
                q_back++;

                parent[out] = node;
            }
        }
    }

    if (!visited[end]) {
        return -1;
    }

    int path_size = 0;
    int p = end;
    while (p != -1) {
        path_size++;
        p = parent[p];
    }

    return path_size;
}

int BusRoutesSolution::numBusesToDestination(vector<vector<int>> &routes, int S, int T) {
    if (S == T) {
        return 0;
    }

    unordered_map<int, vector<int>> index = inverted_index(routes);

    int num_routes = routes.size();
    int start_node = num_routes;
    int end_node = num_routes + 1;

    vector<vector<int>> graph = build_graph(index, num_routes, S, T);
    int path_size = shortest_path(graph, start_node, end_node);

    if (path_size == -1) {
        return -1;
    }
    return path_size - 2;
}