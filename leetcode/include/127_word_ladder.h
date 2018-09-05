#include <string>
#include <vector>
#include <unordered_map>

#define multimap unordered_map<string, vector<string>>
#define smap unordered_map<string, string>

using namespace std;

class WordLadderSolution {
public:
    void add_groups(multimap &groups, string &word);
    multimap create_graph(multimap &groups);

    smap bfs(multimap &graph, string &start, string &end);
    int bfs_ladder_len(string beginWord, string endWord, vector<string> &wordList);

    int bidirectional_bfs(multimap &graph, string &start, string &end);
    int bidirectional_ladder_len(string beginWord, string endWord, vector<string> &wordList);

    int ladderLength(string beginWord, string endWord, vector<string> &wordList);
};
