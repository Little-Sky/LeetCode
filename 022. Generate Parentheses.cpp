// O(n) recursion
// Faster than 10% - 10%

class Solution {
public:
    void generate(vector<string> & res, int le, int ri, string cur) {
        if (!le && !ri) {
            res.push_back(cur);
            return;
        } else {
            if (le){
                generate (res, le-1, ri, cur+'(');
            }
            if (ri > le && ri) {
                generate (res, le, ri-1, cur+')');
            }
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(res, n, n, "");
        return res;
    }
};
