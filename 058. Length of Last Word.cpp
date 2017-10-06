// O(n)
// Faster than 32%

class Solution {
public:
    int lengthOfLastWord(string s) {
        int j = s.length()-1, i;
        while (j >= 0 && isspace(s[j])) j--;
        i = j;
        while (i >= 0 && !isspace(s[i])) i--;
        return j-i;
    }
};
