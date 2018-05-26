#include <string>
#include <vector>

using namespace std;

struct WordDictionaryNode {
    vector<WordDictionaryNode*> next;
};

class WordDictionary {
public:
    WordDictionary();
    void addWord(string word);
    bool search(string word);

private:
    WordDictionaryNode *root;
};