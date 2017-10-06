// O(n) Two iterations
// Faster than 28%

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> width(n, -1); // the current column will be counts twice
        stack<int> S;
        for (int i=0; i<n; i++) {
            while (S.size() && heights[S.top()] >= heights[i]) {
                S.pop();
            }
            int le = S.size() ? S.top() : -1;
            width[i] += i - le;
            // cout << i << " " << width[i] <<endl;
            S.push(i);
        }
        S = stack<int> ();
        for (int i=n-1; i>=0; i--) {
            while (S.size() && heights[S.top()] >= heights[i]) {
                S.pop();
            }
            int ri = S.size() ? S.top() : n;
            width[i] += ri - i;
            // cout << i << " " << width[i] <<endl;
            S.push(i);
        }
        int res = 0;
        for (int i=0; i<n; i++) {
            res = max(res, heights[i] * width[i]);
        }
        return res;
    }
};
