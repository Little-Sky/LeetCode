// O(n!) with some prune
// Faster than 85%

class Solution {
public:
    vector<string> cur;
    
    void dfs(vector<string> & res, string & s, int pos) {
        // cout << pos << " " << cur.size() << " " << (cur.size() ? cur[0] : "") << endl;
        if (cur.size() == 4) {
            if (pos == s.length()) {
                res.push_back(cur[0] + "." + cur[1] + "." + cur[2] + "." + cur[3]);
            }
        } else {
            int num = s[pos] - '0';
            for (int i=pos+1; i<=s.length() && num <= 255; i++) {
                cur.push_back(s.substr(pos, i-pos));
                dfs(res, s, i);
                cur.pop_back();
                if (num == 0) 
                    break;
                if (i < s.length())
                    num = num * 10 + s[i] - '0';
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        dfs(res, s, 0);
        return res;
    }
};
