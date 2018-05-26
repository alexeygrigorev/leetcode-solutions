#include "211_word_dictionary.h"
#include "gtest/gtest.h"

using namespace std;

TEST(WordDictionaryTest, Test0) {
    WordDictionary *wc = new WordDictionary();

    wc->addWord("bad");
    wc->addWord("dad");
    wc->addWord("mad");

    EXPECT_FALSE(wc->search("pad"));
    EXPECT_TRUE(wc->search("bad"));
    EXPECT_TRUE(wc->search(".ad"));
    EXPECT_TRUE(wc->search("b.."));
    EXPECT_FALSE(wc->search("."));
}