// O(mn) O(1) space
// Faster than 70%

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row0 = false, col0 = false;
        if (!matrix.size() || !matrix[0].size())
            return;
        int n = matrix.size(), m = matrix[0].size();
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (!matrix[i][j]) {
                    if (!i)
                        row0 = true;
                    if (!j)
                        col0 = true;
                    if (i && j) {
                        matrix[i][0] = matrix[0][j] = 0;
                    }
                }
            }
        }
        for (int i=1; i<n; i++) {
            for (int j=1; j<m; j++) {
                if (!matrix[i][0] || !matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (row0)
            for (int i=0; i<m; i++)
                matrix[0][i] = 0;
        if (col0)
            for (int i=0; i<n; i++)
                matrix[i][0] = 0;
        
    }
};
