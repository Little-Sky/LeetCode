// O(n * m): string number * string length
// Faster than: 8% - 33%

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size())
            return "";
        for (int res = 0; res < strs[0].size(); res++){
            char cur = strs[0][res];
            for (int i=1; i<strs.size(); i++){
                if (strs[i][res] != cur){
                    return strs[0].substr(0, res);     // -1 +1 cancelled
                }
            }
        }
        return strs[0];
    }
};
