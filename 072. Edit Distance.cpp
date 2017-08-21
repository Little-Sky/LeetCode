// O(mn) memory O(mn)
// Faster than 44%-44%

/*
  Could save more memory by using one row only
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length()+2, vector<int>(word2.length()+2, 1e9));
        if (!word1.length() || !word2.length()) {
            return word1.length() ? word1.length() : word2.length();
        }
        dp[0][0] = 0;
        for (int i=0; i<=word1.length(); i++) {
            for (int j=0; j<=word2.length(); j++) {
                // Delete
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]+1);
                // Insert
                dp[i][j+1] = min(dp[i][j+1], dp[i][j]+1);
                // Equal or replace
                dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + (word1[i] == word2[j] ? 0 : 1));
            }
        }
        // for (auto v : dp){
        //     for (auto n : v)
        //         cout << n << " ";
        //     cout << endl;
        // }
        return dp[word1.length()][word2.length()];
    }
};
