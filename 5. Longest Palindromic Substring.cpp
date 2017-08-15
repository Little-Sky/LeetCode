// O(n^2) two iterations
// Faster than: 66% - 66%

class Solution {
public:
    string longestPalindrome(string & s) {
        start = len = 0;
        for (int i=0; i<s.length(); i++){
            // Try the palindrome center at i
            check (s, i, i);
            // Try the palindrome center between i and i+1
            check (s, i, i+1);
        }
        return s.substr(start, len);
    }

private:
    int start, len;
    inline void check (string & s, int le, int ri) {
        if (le < 0 || ri >= s.length()) {
            return;
        }
        while (le >= 0 && ri <= s.length() && s[le] == s[ri]) {
            le--, ri++;
        }
        if (ri - le - 1 > len) {
            start = le + 1;
            len = ri - le - 1;
        }
    }
};
