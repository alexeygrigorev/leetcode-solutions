#include "017_letter_combination.h"

void LetterCombinationSolution::generate(vector<string> &answers, string prefix, string digits) {
    if (digits.empty()) {
        answers.push_back(prefix);
        return;
    }

    int first = digits[0] - '2';
    string rest = digits.substr(1);
    string chars = pad[first];

    for (int i = 0; i < chars.size(); i++) {
        generate(answers, prefix + chars[i], rest);
    }
}

vector<string> LetterCombinationSolution::letterCombinations(string digits) {
    if (digits.empty()) {
        return {};
    }

    vector<string> answers;
    generate(answers, "", digits);
    return answers;
}
