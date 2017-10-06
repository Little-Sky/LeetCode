// O(n!) Backtracking
// Faster than 65%

class Solution {
public:
    const static int MAXN = 30;
    int vis[3][2*MAXN];
    int pos[MAXN], n;
    
    void dfs (vector<vector<string>> & res, int cur) {
        if (cur == n) {
            vector<string> vec(n, string(n, '.'));
            for (int i=0; i<n; i++)
                vec[i][pos[i]] = 'Q';
            res.push_back(vec);
        } else {
            for (int j=0; j<n; j++) {
                if (!vis[0][j] && !vis[1][cur+j] && !vis[2][cur+n-j]) {
                    pos[cur] = j;
                    vis[0][j] = vis[1][cur+j] = vis[2][cur+n-j] = 1;
                    dfs(res, cur+1);
                    vis[0][j] = vis[1][cur+j] = vis[2][cur+n-j] = 0;
                }
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n_in) {
        n = n_in;
        vector<vector<string>> res;
        memset(vis, 0, sizeof(vis));
        dfs(res, 0);
        return res;
    }
};
