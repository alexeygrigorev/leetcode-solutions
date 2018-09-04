#include <string>
#include <vector>
#include <unordered_map>

#define multimap unordered_map<string, vector<string>>
#define smap unordered_map<string, string>

using namespace std;

class WordLadder2Solution {
public:
    void add_groups(multimap &groups, string &word);
    multimap create_graph(multimap &groups);
    multimap bfs(multimap &graph, string &start, string &end);
    void dfs(vector<vector<string>> &paths, multimap &parents, vector<string> &path,
             string &node, string &end);
    vector<vector<string>> recover_path(string &beginWord, string &endWord,
                                        multimap &parents);

    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList);
};
