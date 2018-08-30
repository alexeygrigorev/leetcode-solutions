#include <vector>
#include <string>

using namespace std;

class LetterCombinationSolution {
public:
    string pad[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void generate(vector<string> &answers, string prefix, string digits);
    vector<string> letterCombinations(string digits);
};
