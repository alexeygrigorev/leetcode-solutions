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

TEST(WordDictionaryTest, Test1) {
    WordDictionary *wd = new WordDictionary();

    wd->addWord("ran");
    wd->addWord("rune");
    wd->addWord("runner");
    wd->addWord("runs");
    wd->addWord("add");
    wd->addWord("adds");
    wd->addWord("adder");
    wd->addWord("addee");

    wd->search("r.n");
    wd->search("ru.n.e");
    wd->search("add");
    wd->search("add.");
    wd->search("adde.");
    wd->search(".an.");
    wd->search("...s");
    wd->search("....e.");
    wd->search(".......");
    wd->search("..n.r");
}

