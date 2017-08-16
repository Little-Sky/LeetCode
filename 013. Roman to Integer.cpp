// O(1)
// Faster than: 58% - 84%

class Solution {
public:
    int romanToInt(string s) {
        const char roman [] = " IVXLCDM";
        const int integer [] = {0, 1, 5, 10, 50, 100, 500, 1000};
        int res = 0;
        s = s + " ";
        for (int i=0; i<s.length()-1; i++){
            int idx1 = strchr(roman, s[i]) - roman;
            int idx2 = strchr(roman, s[i+1]) - roman;
            if (idx2 > idx1){
                res -= integer[idx1];
            } else {
                res += integer[idx1];
            }
        }
        return res;
    }
};
