// O(mn) Two iterations
// Faster than 36%

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (!matrix.size() || !matrix[0].size())
            return 0;
        int n = matrix.size(), m = matrix[0].size();
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                if ((matrix[i][j]-='0') != 0)
                   matrix[i][j] += i ? matrix[i-1][j] : 0;
        // for (auto i : matrix) {
        //     for (auto j : i) {
        //         cout << (int)j << (j >= 10 ? " " : "  ");
        //     }
        //     cout << endl;
        // }
        int res = 0;
        for (int i=0; i<n; i++) {
            vector<int> le(m,-1);
            vector<int> ri(m,m);
            for (int j=0; j<m; j++) {
                int k = j-1;
                while (k >= 0 && matrix[i][j] <= matrix[i][k]) {
                    k = le[k];
                }
                le[j] = k;
            }
            for (int j=m-1; j>=0; j--) {
                int k = j+1;
                while (k < m && matrix[i][j] <= matrix[i][k]) {
                    k = ri[k];
                }
                ri[j] = k;
                res = max (res, (ri[j]-le[j]-1)*matrix[i][j]);
                // if ((ri[j]-le[j]-1)*matrix[i][j] >= 48)
                    // cout << i << " " << j << " " << ri[j] << " " << le[j] <<  endl;
            }
        }
        return res;
    }
};
