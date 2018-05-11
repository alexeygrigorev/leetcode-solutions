#include <vector>
#include <queue>
#include <cstdio>
#include "200_number_islands.h"


void dfs(vector<vector<char>> &grid, pair<int, int> p, vector<bool> &visited) {
    int h = grid.size();
    int w = grid[0].size();

    vector<pair<int, int>> stack;
    stack.push_back(p);

    int delta[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    while (!stack.empty()) {
        pair<int, int> &n = stack.back();
        stack.pop_back();
        int i = n.first;
        int j = n.second;

        for (int k = 0; k < 4; k++) {
            int ni = i + delta[k][0];
            int nj = j + delta[k][1];

            if (ni < 0 || ni >= h) {
                continue;
            }
            if (nj < 0 || nj >= w) {
                continue;
            }
            if (grid[ni][nj] != '1') {
                continue;
            }
            if (visited[nj + w * ni]) {
                continue;
            }

            stack.push_back(make_pair(ni, nj));
        }

        visited[j + w * i] = true;
    }
}


void bfs(vector<vector<char>> &grid, pair<int, int> p, vector<bool> &visited) {
    int h = grid.size();
    int w = grid[0].size();
    int queue_size = h * w + 10;

    vector<pair<int, int>> queue(queue_size);
    int b = 0;
    int e = 0;

    queue[e] = p;
    e++;

    int delta[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    while (e - b > 0) {
        printf("b=%d, e=%d\n", b, e);
        pair<int, int> n = queue[b];
        b = (b + 1) % queue_size;

        int i = n.first;
        int j = n.second;

        for (int k = 0; k < 4; k++) {
            int ni = i + delta[k][0];
            int nj = j + delta[k][1];

            if (ni < 0 || ni >= h) {
                continue;
            }
            if (nj < 0 || nj >= w) {
                continue;
            }
            if (grid[ni][nj] != '1') {
                continue;
            }
            if (visited[nj + w * ni]) {
                continue;
            }

            queue[e] = make_pair(ni, nj);
            visited[nj + w * ni] = true;
            e = (e + 1) % queue_size;
        }
    }
}


int connected_components(vector<vector<char>> &grid) {
    int h = grid.size();
    if (h == 0) {
        return 0;
    }

    int w = grid[0].size();
    int size = h * w;

    vector<bool> visited(size, false);

    int cnt = 0;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!visited[j + w * i] && grid[i][j] == '1') {
                dfs(grid, {i, j}, visited);
                cnt++;
            }
        }
    }
    return cnt;
}

int NumberOfIslandsSolution::numIslands(vector<vector<char>> &grid) {
    return connected_components(grid);
}