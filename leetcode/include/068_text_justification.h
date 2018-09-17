#include <string>
#include <vector>

using namespace std;

class TextJustificationSolution {
public:
    string align_one_word(string &word, int max_width);
    string align_multiple_words(vector<string> &group, int max_width);
    string align_last_line(vector<string> &group, int max_width);
    vector<string> fullJustify(vector<string> &words, int max_width);
};