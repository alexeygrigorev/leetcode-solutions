#include "126_word_ladder_2.h"
#include <queue>
#include <unordered_set>
#include <algorithm>

void WordLadder2Solution::add_groups(multimap &groups, string &word) {
    for (int i = 0; i < word.length(); i++) {
        string copy = word;
        copy[i] = '_';
        groups[copy].push_back(word);
    }
}

multimap WordLadder2Solution::create_graph(multimap &groups) {
    unordered_map<string, vector<string>> graph;

    for (auto pair : groups) {
        vector<string> group = pair.second;
        int group_size = group.size();

        for (int i = 0; i < group_size; i++) {
            string word = group[i];

            for (int j = 0; j < group_size; j++) {
                if (i == j) {
                    continue;
                }
                graph[word].push_back(group[j]);
            }
        }
    }

    return graph;
}

multimap WordLadder2Solution::bfs(multimap &graph, string &start, string &end) {
    queue<string> q;
    q.push(start);

    unordered_map<string, int> distances;
    distances[start] = 0;

    unordered_map<string, vector<string>> parents;

    while (!q.empty()) {
        string from = q.front();
        q.pop();

        if (from == end) {
            break;
        }

        for (string to : graph[from]) {
            if (distances.find(to) == distances.end()) {
                distances[to] = distances[from] + 1;
                parents[to].push_back(from);
                q.push(to);
                continue;
            }

            if (distances[to] == distances[from] + 1) {
                parents[to].push_back(from);
                continue;
            }
        }
    }

    return parents;
}

void WordLadder2Solution::dfs(vector<vector<string>> &paths, multimap &parents,
                              vector<string> &path, string &node, string &end) {
    if (node == end) {
        vector<string> copy = path;
        reverse(copy.begin(), copy.end());
        paths.push_back(copy);
        return;
    }

    for (string parent : parents[node]) {
        path.push_back(parent);
        dfs(paths, parents, path, parent, end);
        path.pop_back();
    }
}

vector<vector<string>> WordLadder2Solution::recover_path(string &beginWord, string &endWord,
               multimap &parents) {
    vector<vector<string>> paths;
    vector<string> path = { endWord };
    dfs(paths, parents, path, endWord, beginWord);
    return paths;
}

vector<vector<string>> WordLadder2Solution::findLadders(string beginWord, string endWord,
                                                        vector<string> &wordList) {
    multimap groups;

    bool found = false;
    for (string w : wordList) {
        if (endWord == w) {
            found = true;
        }
        if (beginWord == w) {
            continue;
        }
        add_groups(groups, w);
    }

    if (!found) {
        return {};
    }

    add_groups(groups, beginWord);

    multimap graph = create_graph(groups);
    multimap parents = bfs(graph, beginWord, endWord);

    return recover_path(beginWord, endWord, parents);
}
