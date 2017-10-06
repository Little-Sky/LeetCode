// O(n)
// Faster than 13%

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        auto itr = intervals.begin();
        while (itr != intervals.end() && itr->end < newInterval.start) 
            itr++;
        if (itr == intervals.end() || itr->start > newInterval.end) {
            intervals.insert(itr, newInterval);
            return intervals;
        } else {
            itr->start = min(itr->start, newInterval.start);
            itr->end = max(itr->end, newInterval.end);
            auto itr2 = itr+1;
            while (itr2 != intervals.end() && itr2->start <= itr->end) {
                itr->end = max(itr->end, itr2->end);
                itr2++;
            }
            intervals.erase(itr+1, itr2);
            return intervals;
        }
    }
};
