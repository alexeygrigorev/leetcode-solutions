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

int WordLadderSolution::ladderLength(string beginWord, string endWord, vector<string> &wordList) {
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
