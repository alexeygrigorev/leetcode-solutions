#include <cstring>
#include "211_word_dictionary.h"

WordDictionaryNode::WordDictionaryNode() {
    this->key = false;
    memset(this->next, 0, 26 * sizeof(WordDictionaryNode *));
}

WordDictionary::WordDictionary() {
    this->root = new WordDictionaryNode();
}

void WordDictionary::addWord(string word) {
    if (word.empty()) {
        return;
    }

    char head = word[0];
    string tail = word.substr(1);
    add_word_recursive(this->root, head, tail);
}

void WordDictionary::add_word_recursive(WordDictionaryNode *node, char head, string tail) {
    char idx = head - 'a';
    if (node->next[idx] == nullptr) {
        node->next[idx] = new WordDictionaryNode();
    }

    WordDictionaryNode *next = node->next[idx];
    if (tail.empty()) {
        next->key = true;
    } else {
        add_word_recursive(next, tail[0], tail.substr(1));
    }
}

bool WordDictionary::search(string word) {
    if (word.empty()) {
        return true;
    }

    WordDictionaryNode *node = this->root;
    return search_recursive(node, word[0], word.substr(1));
}

bool WordDictionary::search_recursive(WordDictionaryNode *node, char head, string tail) {
    char idx = head - 'a';
    if (head != '.') {
        WordDictionaryNode *next = node->next[idx];
        if (next == nullptr) {
            return false;
        }
        if (tail.empty()) {
            return next->key;
        }

        return search_recursive(next, tail[0], tail.substr(1));
    }

    for (char c = 'a'; c <= 'z'; c++) {
        if (search_recursive(node, c, tail)) {
            return true;
        }
    }

    return false;
}