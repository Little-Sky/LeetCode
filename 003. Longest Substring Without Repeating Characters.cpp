// O(n) one iteration
// Faster than 24% - 86% [Facepalm]

/*
  A faster way: use a dict to store the last occurence for each of the character. When hits, jump to the new position.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastOccur(256, -1);
        int le = -1, res = 0;
        for (int ri = 0; ri < s.length(); ri++){
            le = max (le, lastOccur[s[ri]]);
            res = max (res, ri - le);
            lastOccur[s[ri]] = ri;
        }
        return res;
        
// O(n) two iterations
// Faster than 55% - 95%

//         int le=0, ri=0, res=0;
//         vector<bool> used(256, false);
//         // current window is [le, ri)
//         while (ri < s.length()){
//             if (!used[s[ri]]) {
//                 used[s[ri++]] = true;
//                 res = max(res, ri-le);
//             } else {
//                 while (used[s[ri]]){
//                     used[s[le++]] = false;
//                 }
//             }
//         }
//         return res;
    }
};
