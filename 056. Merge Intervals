// O(n) one iteration
// Faster than 65%

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int le=0, ri=0;
        sort(intervals.begin(), intervals.end(), 
             [](Interval & a, Interval & b) {
                 return a.start < b.start || (a.start==b.start && a.end < b.end);
             });
        while (ri < intervals.size()) {
            intervals[le].start = intervals[ri].start;
            int ed = intervals[ri].end;
            while (ri < intervals.size() && ed >= intervals[ri].start)
                ed = max(ed, intervals[ri].end), ri++;
            intervals[le++].end = ed;            
        }
        intervals.resize(le);
        return intervals;
    }
};
