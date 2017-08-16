// Manacher's algorithm
// O(n) Two iterations
// Faster than 60% - 76%
// Tutorial: http://articles.leetcode.com/longest-palindromic-substring-part-ii

class Solution {
private: 
    // "abc" -> "^#a#b#c$", where '^' and '$' are sentinels appended to avoid boundary checkings.
    string precompute (const string & s) {
        string res = "^";
        for (int i=0; i<s.length(); i++){
            // cout << typeid(s[i]).name() << endl;
            res += '#';     // Don't put them on the same line!
            res += s[i];    // a char
        }
        res += "#$";
        return res;
    }
    
public:
    string longestPalindrome (string & s) {
        // Center, rightmost palindrome ending.
        int C=0, R=0;
        string T = precompute(s);
        vector<int> res (T.length(), 0);
        // From '^' to '$'
        for (int i=1; i<T.length()-1; i++){
            int i_mirror = 2*C - i;  // reflected point around C
            res[i] = R > i ? min(R-i, res[i_mirror]) : 0;
            while (T[i + res[i] + 1] == T[i - res[i] -1]) {
                res[i]++;
            }
            if (i + res[i] > R){
                R = i + res[i];
                C = i;
            }
        }
        // cout << T << endl;
        int center_index = 0, max_len = 0;
        for (int i=1; i<T.length()-1; i++){
            cout << res[i];
            if (res[i] > max_len){
                max_len = res[i];
                center_index = i;
            }
        }
        return s.substr((center_index - max_len - 1)/2, max_len);
        
        
// Swapping windows
// O(n^2) two iterations
// Faster than: 66% - 66%

//         int start=0,  len = 0;
//         for (int i=0; i<s.length(); i++){
//             // Try the palindrome center at i
//             int le = i, ri = i;
//             if (le >= 0 && ri < s.length()) {
//                 while (le >= 0 && ri <= s.length() && s[le] == s[ri]) {
//                     le--, ri++;
//                 }
//                 if (ri - le - 1 > len) {
//                     start = le + 1;
//                     len = ri - le - 1;
//                 }
//             }
//             le = i, ri = i+1;
//             if (le >= 0 && ri < s.length()) {
//                 while (le >= 0 && ri <= s.length() && s[le] == s[ri]) {
//                     le--, ri++;
//                 }
//                 if (ri - le - 1 > len) {
//                     start = le + 1;
//                     len = ri - le - 1;
//                 }
//             }
//             // check (s, i, i);
//             // Try the palindrome center between i and i+1
//             // check (s, i, i+1);
//         }
//         return s.substr(start, len);
    }
};
