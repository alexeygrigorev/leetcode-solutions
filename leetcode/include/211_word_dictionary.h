#include <string>

using namespace std;

struct WordDictionaryNode {
    bool key;
    WordDictionaryNode* next[26];
    WordDictionaryNode();
};

class WordDictionary {
public:
    WordDictionary();
    void addWord(string word);
    bool search(string word);

private:
    WordDictionaryNode *root;
    void add_word_recursive(WordDictionaryNode *node, char head, string tail);
    bool search_recursive(WordDictionaryNode *node, char head, string tail);
};