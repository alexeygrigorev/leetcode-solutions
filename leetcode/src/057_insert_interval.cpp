#include "057_insert_interval.h"

vector<Interval> InsertIntervalSolution::insert(vector<Interval> &intervals, Interval i) {
    if (intervals.empty()) {
        return { i };
    }

    vector<Interval> result;

    auto it = intervals.begin();

    while (it != intervals.end() && it->start < i.start) {
        result.push_back(*it);
        it++;
    }

    if (!result.empty()) {
        if (result.back().end >= i.start) {
            if (i.end > result.back().end) {
                result.back().end = i.end;
            }
        } else {
            result.push_back(i);
        }
    } else {
        result.push_back(i);
    }

    while (it != intervals.end() && result.back().end >= it->start) {
        if (result.back().end <= it->end) {
            result.back().end = it->end;
        }
        it++;
    }

    while (it != intervals.end()) {
        result.push_back(*it);
        it++;
    }

    return result;
}
