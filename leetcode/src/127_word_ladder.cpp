#include "127_word_ladder.h"
#include <queue>
#include <unordered_set>

void WordLadderSolution::add_groups(multimap &groups, string &word) {
    for (int i = 0; i < word.length(); i++) {
        string copy = word;
        copy[i] = '_';
        groups[copy].push_back(word);
    }
}

multimap WordLadderSolution::create_graph(multimap &groups) {
    multimap graph;

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

smap WordLadderSolution::bfs(multimap &graph, string &start, string &end) {
    queue<string> q;
    q.push(start);

    unordered_set<string> visited;
    visited.insert(start);

    unordered_map<string, string> parent;
    parent[start] = "<start>";

    while (!q.empty()) {
        string &word = q.front();
        q.pop();

        if (word == end) {
            break;
        }

        for (string to : graph[word]) {
            if (visited.count(to) > 0) {
                continue;
            }
            visited.insert(to);
            parent[to] = word;
            q.push(to);
        }
    }

    return parent;
}

int WordLadderSolution::bfs_ladder_len(string beginWord, string endWord, vector<string> &wordList) {
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
        return 0;
    }

    add_groups(groups, beginWord);

    multimap graph = create_graph(groups);
    smap parent = bfs(graph, beginWord, endWord);

    int len = 0;
    string word = endWord;

    while (word != "<start>") {
        len++;
        word = parent[word];
        if (word == "") {
            return 0;
        }
    }

    return len;
}

int WordLadderSolution::bidirectional_bfs(multimap &graph, string &start, string &end) {
    queue<string> q1;
    unordered_set<string> s1;
    unordered_map<string, int> dist1;
    q1.push(start);
    s1.insert(start);
    dist1[start] = 0;

    queue<string> q2;
    unordered_set<string> s2;
    unordered_map<string, int> dist2;
    q2.push(end);
    s2.insert(end);
    dist2[end] = 0;

    unordered_set<string> visited;
    visited.insert(start);
    visited.insert(end);

    while (!q1.empty() && !q2.empty()) {
        if (!q1.empty()) {
            string &word = q1.front();
            q1.pop();

            if (word == end) {
                return dist1[word];
            }


            for (string to : graph[word]) {
                if (s2.count(to) > 0) {
                    return dist1[word] + dist2[to] + 2;
                }

                if (visited.count(to) > 0) {
                    continue;
                }

                dist1[to] = dist1[word] + 1;
                visited.insert(to);
                q1.push(to);
                s1.insert(to);
            }
        }

        if (!q2.empty()) {
            string &word = q2.front();
            q2.pop();

            if (word == start) {
                return dist2[word];
            }

            for (string to : graph[word]) {
                if (s1.count(to) > 0) {
                    return dist1[to] + dist2[word] + 2;
                }

                if (visited.count(to) > 0) {
                    continue;
                }

                dist2[to] = dist2[word] + 1;
                visited.insert(to);
                q2.push(to);
                s2.insert(to);
            }
        }
    }

    return 0;
}

int WordLadderSolution::bidirectional_ladder_len(string beginWord, string endWord, vector<string> &wordList) {
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
        return 0;
    }

    add_groups(groups, beginWord);

    multimap graph = create_graph(groups);
    return bidirectional_bfs(graph, beginWord, endWord);
}

int WordLadderSolution::ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    return bidirectional_ladder_len(beginWord, endWord, wordList);
}
