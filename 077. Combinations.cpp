// O(C(n.k))
// Faster than 41%

class Solution {
public:
    vector<int> cur;
    
    void dfs(vector<vector<int>> & res, int k, int st, int ed) {
        if (!k && cur.size()) {
            res.push_back(cur);
        } else {
            for (int i=st; i<=ed-k+1; i++) {
                cur.push_back(i);
                dfs(res, k-1, i+1, ed);
                cur.pop_back();
            }
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        dfs(res, k, 1, n);
        return res;
    }
};
