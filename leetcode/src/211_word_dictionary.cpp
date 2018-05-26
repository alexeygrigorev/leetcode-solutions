#include "211_word_dictionary.h"

WordDictionaryNode* new_tree_node() {
    WordDictionaryNode *node = new WordDictionaryNode();
    for (int i = 0; i < 128; i++) {
        node->next.push_back(nullptr);
    }
    return node;
}

WordDictionary::WordDictionary() {
    this->root = new_tree_node();
}

void add_word(WordDictionaryNode *node, char head, string tail) {
    if (node->next[head] == nullptr) {
        node->next[head] = new_tree_node();
    }

    WordDictionaryNode *next = node->next[head];
    if (!tail.empty()) {
        add_word(next, tail[0], tail.substr(1));
    }
}

void WordDictionary::addWord(string word) {
    if (word.empty()) {
        return;
    }

    char head = word[0];
    string tail = word.substr(1) + "!"; // ! is end of word
    add_word(this->root, head, tail);
}

bool search_recursive(WordDictionaryNode *node, char head, string tail) {
    if (head != '.') {
        if (node->next[head] == nullptr) {
            return false;
        }
        if (tail.empty()) {
            return true;
        }

        return search_recursive(node->next[head], tail[0], tail.substr(1));
    }

    for (char c = 'a'; c <= 'z'; c++) {
        WordDictionaryNode *next = node->next[c];
        if (next == nullptr) {
            continue;
        }

        if (search_recursive(node, c, tail)) {
            return true;
        }
    }

    return false;
}

bool WordDictionary::search(string word) {
    if (word.empty()) {
        return true;
    }

    WordDictionaryNode *node = this->root;
    return search_recursive(node, word[0], word.substr(1) + "!");
}