#include <algorithm>
#include "056_merge_intervals.h"

bool compare(const Interval &i1, const Interval &i2) {
    return i1.start < i2.start;
}

vector<Interval> MergeIntervalsSolution::merge(vector<Interval> &intervals) {
    if (intervals.size() <= 1) {
        return intervals;
    }

    sort(intervals.begin(), intervals.end(), compare);

    vector<Interval> result;
    result.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
        Interval interval = intervals[i];
        if (interval.start <= result.back().end) {
            if (interval.end >= result.back().end) {
                result.back().end = interval.end;
            }
        } else {
            result.push_back(interval);
        }
    }

    return result;
}
