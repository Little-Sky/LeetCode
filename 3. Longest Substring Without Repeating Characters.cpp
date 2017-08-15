// O(n) two iterations
// Faster than 55% - 95%

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int le=0, ri=0, res=0;
        vector<bool> used(256, false);
        // current window is [le, ri)
        while (ri < s.length()){
            if (!used[s[ri]]) {
                used[s[ri++]] = true;
                res = max(res, ri-le);
            } else {
                while (used[s[ri]]){
                    used[s[le++]] = false;
                }
            }
        }
        return res;
    }
};
