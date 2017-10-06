// O(n!) Backtracking 
// Faster than 33%

class Solution {
public:
    const static int MAXN = 30;
    int vis[3][2*MAXN];
    
    int dfs (int n, int cur) {
        if (cur == n) {
            return 1;
        } else {
            int res = 0;
            for (int j=0; j<n; j++) {
                if (!vis[0][j] && !vis[1][cur+j] && !vis[2][cur+n-j]) {
                    vis[0][j] = vis[1][cur+j] = vis[2][cur+n-j] = 1;
                    res += dfs(n, cur+1);
                    vis[0][j] = vis[1][cur+j] = vis[2][cur+n-j] = 0;
                }
            }
            return res;
        }
    }
    int totalNQueens(int n) {
        memset(vis, 0, sizeof(vis));
        return dfs(n, 0);
    }
};
