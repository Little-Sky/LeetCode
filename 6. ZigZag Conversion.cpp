// O(n)
// Faster than: 65% - 75%

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        int dist = (numRows - 1) * 2;
        int dist2 = dist;
        string res = "";
        for (int row=0; row<numRows; row++) {
            int index = row;
            while (index < s.length()) {
                res += s[index];
                if (dist2 != dist && dist2 != 0 && index + dist2 < s.length()) {
                    res += s[index + dist2];
                }
                index += dist;
            }
            dist2 -= 2;
        }
        return res;
    }
};
