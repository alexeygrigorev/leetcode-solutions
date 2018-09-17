#include "068_text_justification.h"
#include <sstream>

string TextJustificationSolution::align_one_word(string &word, int max_width) {
    int len = word.length();

    if (len < max_width) {
        return word + string(max_width - len, ' ');
    }

    return word;
}

string TextJustificationSolution::align_multiple_words(vector<string> &group, int max_width) {
    int num_words = group.size();
    int num_spaces = num_words - 1;
    vector<int> spaces(num_spaces, 1);

    int total_len = num_spaces;
    for (const string &word : group) {
        total_len = total_len + word.length();
    }

    int i = 0;
    while (total_len < max_width) {
        spaces[i]++;
        total_len++;
        i = (i + 1) % num_spaces;
    }

    stringstream out;
    for (int i = 0; i < num_spaces; i++) {
        out << group[i] << string(spaces[i], ' ');
    }

    out << group.back();
    return out.str();
}

string TextJustificationSolution::align_last_line(vector<string> &group, int max_width) {
    stringstream out;

    int current_len = group[0].length();
    out << group[0];

    for (int i = 1; i < group.size(); i++) {
        out << " " << group[i];
        current_len = current_len + 1 + group[i].length();
    }

    while (current_len < max_width) {
        out << " ";
        current_len++;
    }

    return out.str();
}

vector<string> TextJustificationSolution::fullJustify(vector<string> &words, int max_width) {
    vector<vector<string>> grouped;

    vector<string> current = { words[0] };
    int current_len = words[0].length();

    for (int i = 1; i < words.size(); i++) {
        string word = words[i];

        if (current_len + 1 + word.length() <= max_width) {
            current_len = current_len + 1 + word.length();
            current.push_back(word);
        } else {
            grouped.push_back(current);
            current = { word };
            current_len = word.length();
        }
    }

    if (!current.empty()) {
        grouped.push_back(current);
    }

    vector<string> result;
    int num_groups = grouped.size();

    for (int i = 0; i < num_groups - 1; i++) {
        vector<string> group = grouped[i];

        if (group.size() == 1) {
            string line = align_one_word(group[0], max_width);
            result.push_back(line);
        } else {
            string line = align_multiple_words(group, max_width);
            result.push_back(line);
        }
    }

    string line = align_last_line(grouped.back(), max_width);
    result.push_back(line);

    return result;
}
