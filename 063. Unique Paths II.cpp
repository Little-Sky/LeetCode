// O(mn) O(n) memory
// Faster than 15%

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& G) {
        if (!G.size() || !G[0].size() || G[0][0] || G.back().back())
            return 0;
        vector<int> dp(110, 0);
        dp[0] = 1;
        for (int i=0; i<G.size(); i++) {
            for (int j=0; j<G[0].size(); j++) {
                if (G[i][j]) {
                    dp[j] = 0;
                } else {
                    dp[j] += j ? dp[j-1] : 0;
                }
            }
        }
        return dp[G[0].size()-1];
        
    }
};
